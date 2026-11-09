// Ghidra decompilation of functions from tfc/player.cpp
// 155 functions, ordered by original source line

// player  @ 00102330  (line 225)

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
  *puVar1 = &PTR__CBasePlayer_001892a8;
  puVar1[0x392] = 1;
  puVar1[0x242] = 0;
  (*g_engfuncs.pfnTime)();
  puVar1[1] = pev;
  puVar1[0x391] = (float)(extraout_ST0 + (longdouble)5.0);
  return;
}


// AmmoDamage  @ 001023d0  (line 281)

float AmmoDamage(char *pName)

{
  float fVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  bVar5 = false;
  bVar6 = pName == (char *)0x0;
  fVar1 = 0.0;
  if (!bVar6) {
    iVar2 = 4;
    pbVar3 = (byte *)pName;
    pbVar4 = &DAT_0017fd01;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    if (bVar6) {
      return gSkillData.plrDmg9MM;
    }
    iVar2 = 4;
    bVar6 = false;
    pbVar3 = (byte *)pName;
    pbVar4 = (byte *)0x17ec0e;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    if (bVar6) {
      return gSkillData.plrDmg357;
    }
    iVar2 = 0xb;
    bVar6 = false;
    pbVar3 = (byte *)pName;
    pbVar4 = (byte *)0x17ebd0;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    if (bVar6) {
      return gSkillData.plrDmgM203Grenade;
    }
    iVar2 = 9;
    bVar6 = false;
    pbVar3 = (byte *)pName;
    pbVar4 = (byte *)0x17ebe0;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    fVar1 = gSkillData.plrDmgBuckshot;
    if (!bVar6) {
      iVar2 = 6;
      bVar6 = false;
      pbVar3 = (byte *)pName;
      pbVar4 = (byte *)"bolts";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pbVar3 < *pbVar4;
        bVar6 = *pbVar3 == *pbVar4;
        pbVar3 = pbVar3 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar6);
      fVar1 = gSkillData.plrDmgCrossbowMonster;
      if (!bVar6) {
        iVar2 = 8;
        bVar6 = false;
        pbVar3 = (byte *)pName;
        pbVar4 = (byte *)0x193403;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pbVar3 < *pbVar4;
          bVar6 = *pbVar3 == *pbVar4;
          pbVar3 = pbVar3 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar6);
        fVar1 = gSkillData.plrDmgRPG;
        if (!bVar6) {
          iVar2 = 8;
          bVar6 = false;
          pbVar3 = (byte *)pName;
          pbVar4 = (byte *)"uranium";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar5 = *pbVar3 < *pbVar4;
            bVar6 = *pbVar3 == *pbVar4;
            pbVar3 = pbVar3 + 1;
            pbVar4 = pbVar4 + 1;
          } while (bVar6);
          fVar1 = gSkillData.plrDmgGauss;
          if (!bVar6) {
            iVar2 = 0xd;
            bVar6 = false;
            pbVar3 = (byte *)pName;
            pbVar4 = (byte *)"Hand Grenade";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar5 = *pbVar3 < *pbVar4;
              bVar6 = *pbVar3 == *pbVar4;
              pbVar3 = pbVar3 + 1;
              pbVar4 = pbVar4 + 1;
            } while (bVar6);
            fVar1 = gSkillData.plrDmgHandGrenade;
            if (!bVar6) {
              iVar2 = 0xf;
              bVar6 = false;
              pbVar3 = (byte *)pName;
              pbVar4 = (byte *)"Satchel Charge";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar5 = *pbVar3 < *pbVar4;
                bVar6 = *pbVar3 == *pbVar4;
                pbVar3 = pbVar3 + 1;
                pbVar4 = pbVar4 + 1;
              } while (bVar6);
              fVar1 = gSkillData.plrDmgSatchel;
              if (!bVar6) {
                iVar2 = 10;
                bVar6 = false;
                pbVar3 = (byte *)"Trip Mine";
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar5 = (byte)*pName < *pbVar3;
                  bVar6 = *pName == *pbVar3;
                  pName = pName + 1;
                  pbVar3 = pbVar3 + 1;
                } while (bVar6);
                fVar1 = gSkillData.plrDmgTripmine;
                if ((!bVar5 && !bVar6) != bVar5) {
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


// UpdateStatsFile  @ 00102540  (line 311)

void UpdateStatsFile(float dataTime,char *pMapname,float health,float ammo,int skillLevel)

{
  FILE *__stream;
  
                    /* Unresolved local var: FILE * fp@[???] */
  __stream = fopen("stats.txt","a");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%6.2f, %6.2f, %6.2f, %s, %2d\n",(double)dataTime,(double)health,(double)ammo,
            pMapname,skillLevel);
    fclose(__stream);
    return;
  }
  return;
}


// UpdateStats  @ 001025f0  (line 340)

void UpdateStats(CBasePlayer *pPlayer)

{
  int *piVar1;
  CBasePlayerItem *pCVar2;
  entvars_t *peVar3;
  char *pcVar4;
  string_t sVar5;
  float fVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  FILE *__stream;
  int iVar10;
  longdouble extraout_ST0;
  float fVar11;
  float local_d8;
  int aiStack_cc [33];
  char *local_48 [14];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int[32] ammoCount@[???]
                       Unresolved local var: float ammo@[???]
                       Unresolved local var: float health@[???]
                       Unresolved local var: float ammoDelta@[???]
                       Unresolved local var: float healthDelta@[???]
                       Unresolved local var: int forceWrite@[???] */
  uVar7 = 0;
  do {
    *(undefined4 *)((int)aiStack_cc + uVar7) = *(undefined4 *)((int)pPlayer->m_rgAmmo + uVar7);
    uVar7 = uVar7 + 4;
  } while (uVar7 < 0x80);
  fVar11 = gpGlobals->time;
  fVar6 = fVar11;
  if (fVar11 < gStats.lastGameTime) {
    gStats.dataTime = gStats.gameTime;
    fVar6 = gpGlobals->time;
    gStats.lastGameTime = fVar11;
  }
  local_d8 = 0.0;
  gStats.gameTime = gStats.gameTime + (fVar6 - gStats.lastGameTime);
  gStats.lastGameTime = gpGlobals->time;
  do {
                    /* Unresolved local var: CBasePlayerItem * p@[???] */
    for (pCVar2 = pPlayer->m_rgpPlayerItems[(int)local_d8]; pCVar2 != (CBasePlayerItem *)0x0;
        pCVar2 = pCVar2->m_pNext) {
                    /* Unresolved local var: ItemInfo II@[???]
                       Unresolved local var: int index@[DW_OP_reg3(EBX)] */
      uVar7 = 0;
      do {
        uVar8 = uVar7;
        *(undefined4 *)((int)local_48 + uVar8) = 0;
        *(undefined4 *)((int)local_48 + uVar8 + 4) = 0;
        *(undefined4 *)((int)local_48 + uVar8 + 8) = 0;
        *(undefined4 *)((int)local_48 + uVar8 + 0xc) = 0;
        uVar7 = uVar8 + 0x10;
      } while (uVar7 < 0x20);
      *(undefined4 *)((int)local_48 + uVar7) = 0;
      *(undefined4 *)((int)local_48 + uVar8 + 0x14) = 0;
      *(undefined4 *)((int)local_48 + uVar8 + 0x18) = 0;
      (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45])
                (pCVar2,local_48);
      pcVar4 = local_48[2];
                    /* Unresolved local var: int i@[???] */
      if (local_48[2] != (char *)0x0) {
        iVar10 = 1;
        do {
          if ((CBasePlayerItem::AmmoInfoArray[iVar10].pszName != (char *)0x0) &&
             (iVar9 = strcasecmp(pcVar4,CBasePlayerItem::AmmoInfoArray[iVar10].pszName), iVar9 == 0)
             ) {
            aiStack_cc[iVar10] =
                 aiStack_cc[iVar10] +
                 pCVar2[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.tf_items;
            break;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 0x20);
      }
    }
    local_d8 = (float)((int)local_d8 + 1);
    if (local_d8 == 8.40779e-45) {
      iVar10 = 1;
      local_d8 = 0.0;
      do {
        fVar11 = AmmoDamage(CBasePlayerItem::AmmoInfoArray[iVar10].pszName);
        piVar1 = aiStack_cc + iVar10;
        iVar10 = iVar10 + 1;
        local_d8 = (float)*piVar1 * fVar11 + local_d8;
      } while (iVar10 != 0x20);
      peVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
      fVar11 = peVar3->armorvalue;
      fVar11 = fVar11 + fVar11 + peVar3->health;
      if (((10.0 < ABS(local_d8 - (float)gStats.lastAmmo)) ||
          (10.0 < ABS(fVar11 - gStats.lastHealth))) && (0.0 < fVar11 || gStats.lastHealth <= 0.0)) {
        if (gStats.nextOutputTime == 0.0) {
          gStats.dataTime = gStats.gameTime;
        }
        gStats.lastHealth = fVar11;
        gStats.lastAmmo = (int)local_d8;
        gStats.nextOutputTime = gStats.gameTime + 3.0;
        return;
      }
      if (((gStats.nextOutputTime != 0.0) && (gStats.nextOutputTime < gStats.gameTime)) ||
         (0.0 >= fVar11 && gStats.lastHealth > 0.0)) {
                    /* Unresolved local var: FILE * fp@[???] */
        (*g_engfuncs.pfnCVarGetFloat)("skill");
        fVar6 = gStats.dataTime;
        pcVar4 = gpGlobals->pStringBase;
        sVar5 = gpGlobals->mapname;
        __stream = fopen("stats.txt","a");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%6.2f, %6.2f, %6.2f, %s, %2d\n",(double)fVar6,(double)fVar11,
                  (double)local_d8,pcVar4 + sVar5,(int)extraout_ST0);
          fclose(__stream);
        }
        gStats.lastAmmo = (int)local_d8;
        gStats.nextOutputTime = 0.0;
        gStats.lastOutputTime = gStats.gameTime;
        gStats.lastHealth = fVar11;
      }
      return;
    }
  } while( true );
}


// CBasePlayer::PainSound  @ 00101830  (line 411)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PainSound(CBasePlayer * this) */

void __thiscall CBasePlayer::PainSound(CBasePlayer *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  int32 iVar3;
  longdouble lVar4;
  char *sample;
  
                    /* Unresolved local var: int rs@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (0.0 <= peVar1->health) {
                    /* Unresolved local var: int rs@[???] */
    if ((peVar1->watertype == -3) && (peVar1->waterlevel == 3)) {
      lVar4 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,1.0);
      if (lVar4 <= (longdouble)0.5) {
        sample = "player/drown2.wav";
      }
      else {
        sample = "player/drown1.wav";
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
        pgVar2 = gpGlobals;
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->noise =
             (string_t)("5. #Nothing \n\n" + (0xe - (int)gpGlobals->pStringBase));
        peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (iVar3 == 1) {
          peVar1->noise = (int)"player/pain1.wav" - (int)pgVar2->pStringBase;
        }
        else if (iVar3 == 2) {
          peVar1->noise = (int)"player/pain2.wav" - (int)pgVar2->pStringBase;
        }
        else if (iVar3 == 3) {
          peVar1->noise = (int)"player/pain3.wav" - (int)pgVar2->pStringBase;
        }
        else if (iVar3 == 4) {
          peVar1->noise = (int)"player/pain4.wav" - (int)pgVar2->pStringBase;
        }
        else if (iVar3 == 5) {
          peVar1->noise = (int)"player/pain5.wav" - (int)pgVar2->pStringBase;
        }
        else {
          peVar1->noise = (int)"player/pain6.wav" - (int)pgVar2->pStringBase;
        }
        peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        EMIT_SOUND_DYN(peVar1->pContainingEntity,2,pgVar2->pStringBase + peVar1->noise,1.0,0.8,0,100
                      );
        return;
      }
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.axhitme = 0;
      sample = "player/axhit1.wav";
    }
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,sample,1.0,0.8,0,
                   100);
  }
  return;
}


// VecVelocityForDamage  @ 00102930  (line 467)

Vector * VecVelocityForDamage(Vector *__return_storage_ptr__,float flDamage)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
                    /* Unresolved local var: Vector vec@[???] */
  lVar1 = (longdouble)(*g_engfuncs.pfnRandomFloat)(200.0,300.0);
  lVar2 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(-100.0,100.0);
  __return_storage_ptr__->x = (float)lVar3;
  lVar4 = (longdouble)(float)lVar2;
  __return_storage_ptr__->y = (float)lVar2;
  lVar2 = (longdouble)(float)lVar1;
  __return_storage_ptr__->z = (float)lVar1;
  if (-50.0 < flDamage) {
    lVar1 = (longdouble)0.7;
  }
  else {
    if (-200.0 < flDamage) {
      __return_storage_ptr__->x = (float)(lVar3 + lVar3);
      __return_storage_ptr__->y = (float)(lVar4 + lVar4);
      __return_storage_ptr__->z = (float)(lVar2 + lVar2);
      return __return_storage_ptr__;
    }
    lVar1 = (longdouble)10.0;
  }
  __return_storage_ptr__->x = (float)(lVar3 * lVar1);
  __return_storage_ptr__->y = (float)(lVar4 * lVar1);
  __return_storage_ptr__->z = (float)(lVar2 * lVar1);
  return __return_storage_ptr__;
}


// TrainSpeed  @ 00102a00  (line 525)

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


// CBasePlayer::CBasePlayer  @ 00102a60  (line 549)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CBasePlayer(CBasePlayer * this) */

void __thiscall CBasePlayer::CBasePlayer(CBasePlayer *this)

{
  longdouble extraout_ST0;
  
  this->m_nFirstSpawn = 1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBasePlayer_001892a8;
  this->m_pszLastItem = (char *)0x0;
  (*g_engfuncs.pfnTime)();
  this->m_DB_LastTimingTestTime = (float)(extraout_ST0 + (longdouble)5.0);
  return;
}


// CBasePlayer::DeathSound  @ 001016b0  (line 563)

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


// CBasePlayer::TakeHealth  @ 0010c6e0  (line 592)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int TakeHealth(CBasePlayer * this, float flHealth, int bitsDamageType)
    */

int __thiscall CBasePlayer::TakeHealth(CBasePlayer *this,float flHealth,int bitsDamageType)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  int iVar5;
  
                    /* Unresolved local var: BOOL bResult@[???] */
  if ((bitsDamageType & 0x1000000U) == 0) {
    iVar5 = CBaseMonster::TakeHealth(&this->super_CBaseMonster,flHealth,bitsDamageType);
  }
  else {
    piVar1 = &(this->super_CBaseMonster).m_bitsDamageType;
    *piVar1 = *piVar1 & ~(bitsDamageType & 0xff003fffU);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar4->health = flHealth + peVar4->health;
    iVar5 = 1;
  }
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.leg_damage;
  if (0.0 < fVar2) {
                    /* Unresolved local var: BOOL bResult@[???] */
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar3 = peVar4->health;
    if ((peVar4->max_health - 5.0 <= fVar3) ||
       (fVar2 = fVar2 - (fVar3 + flHealth) / 20.0,
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.leg_damage = fVar2, fVar2 < 1.0)) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.leg_damage = 0.0;
    }
    TeamFortress_SetSpeed(this);
    iVar5 = 1;
  }
  return iVar5;
}


// CBasePlayer::TraceAttack  @ 0010c3f0  (line 630)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TraceAttack(CBasePlayer * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBasePlayer::TraceAttack
          (CBasePlayer *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,TraceResult *ptr,
          int bitsDamageType)

{
  uint uVar1;
  Vector vecSpot;
  BOOL BVar2;
  int iVar3;
  edict_t *peVar4;
  CBasePlayer *pOther;
  int in_stack_ffffffa0;
  float in_stack_ffffffa4;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->takedamage == 0.0) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pAttacker@[DW_OP_reg2(EDX)]
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
    iVar3 = *(int *)((int)vecDir.y + 0x34);
    if (iVar3 == 1) {
      in_stack_ffffffa0 = 0;
      in_stack_ffffffa4 = 0.0;
      flDamage = flDamage + flDamage;
      ClientPrint((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Sniper_headshot",(char *)0x0,
                  (char *)0x0,(char *)0x0,(char *)0x0);
      (pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.deathtype =
           (string_t)("#Sniper_headshot" + (8 - (int)gpGlobals->pStringBase));
    }
    else if ((0 < iVar3) && (iVar3 - 6U < 2)) {
      BVar2 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther);
      if ((BVar2 == 0) || ((pOther == this || (((int)gpGlobals->teamplay & 0x1eU) == 0)))) {
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
      in_stack_ffffffa4 = 0.0;
      in_stack_ffffffa0 = 0;
      ClientPrint((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Sniper_legshot",(char *)0x0,(char *)0x0
                  ,(char *)0x0,(char *)0x0);
    }
  }
  BVar2 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther);
  if ((BVar2 != 0) && (pOther != this)) {
    if (((uint)vecDir.z & 0x40) == 0) {
      uVar1 = (int)gpGlobals->teamplay & 4;
    }
    else {
      uVar1 = (int)gpGlobals->teamplay & 0x10;
    }
    if (uVar1 != 0) goto LAB_0010c5c8;
  }
  iVar3 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x10])(this);
  local_34 = *(undefined4 *)((int)vecDir.y + 0x14);
  local_30 = *(undefined4 *)((int)vecDir.y + 0x18);
  local_2c = *(undefined4 *)((int)vecDir.y + 0x1c);
  vecSpot.y = (vec_t)iVar3;
  vecSpot.x = (vec_t)&local_34;
  vecSpot.z = flDamage;
  SpawnBlood(vecSpot,in_stack_ffffffa0,in_stack_ffffffa4);
  local_28 = *(undefined4 *)vecDir.x;
  local_24 = *(undefined4 *)((int)vecDir.x + 4);
  local_20 = *(undefined4 *)((int)vecDir.x + 8);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x11])(this,flDamage,&local_28,vecDir.y,vecDir.z);
LAB_0010c5c8:
  AddMultiDamage(pevAttacker,(CBaseEntity *)this,flDamage,(int)vecDir.z);
  return;
}


// CBasePlayer::TakeDamage  @ 0010fbe0  (line 708)

/* WARNING: Variable defined which should be unmapped: bWasHurt */
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
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  _func_void_int *p_Var7;
  int iVar8;
  int iVar9;
  CBasePlayer *pCVar10;
  CBasePlayer *pCVar11;
  int iVar12;
  BOOL BVar13;
  uint uVar14;
  edict_t *peVar15;
  entvars_t *peVar16;
  globalvars_t *pgVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  float fVar28;
  entvars_t *local_90;
  int local_48;
  BOOL bWasHurt;
  
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[???]
                       Unresolved local var: int iTookDamage@[???] */
  iVar8 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
  if (iVar8 == 0) {
    return 0;
  }
  if (cease_fire != 0) {
    return 0;
  }
                    /* Unresolved local var: int bitsDamage@[???]
                       Unresolved local var: int ffound@[???]
                       Unresolved local var: BOOL bAttackerIsPlayer@[???]
                       Unresolved local var: CBaseEntity * pAttacker@[DW_OP_reg7(EDI)]
                       Unresolved local var: int iTookDamage@[???]
                       Unresolved local var: BOOL bWasHurt@[???]
                       Unresolved local var: float flBounceDamage@[???]
                       Unresolved local var: float flHealthPrev@[???] */
  peVar15 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar15 == (edict_t *)0x0) &&
     (peVar15 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar15 == (edict_t *)0x0)) {
    return 0;
  }
  pCVar10 = peVar15->pvPrivateData;
  if (pCVar10 == (CBasePlayer *)0x0) {
    return 0;
  }
  iVar8 = (*(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[10])(pCVar10);
  if (iVar8 == 2) {
    if ((pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no == 0) {
      return 0;
    }
    flDamage = flDamage * 0.9;
    if ((pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.super_damage_finished <= gpGlobals->time) {
      bVar18 = true;
      bVar27 = true;
    }
    else {
      flDamage = flDamage * 4.0;
      bVar18 = true;
      bVar27 = true;
    }
  }
  else {
    bVar18 = false;
    bVar27 = false;
  }
  if ((tfc_balance_teams.value != 0.0) || (tfc_balance_scores.value != 0.0)) {
    flDamage = TeamEqualiseDamage((CBaseEntity *)this,(CBaseEntity *)pCVar10,flDamage);
  }
  local_48 = (int)flDamage;
  this->m_lastDamageAmount = local_48;
  uVar14 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.armorclass;
  fVar3 = flDamage;
  if (uVar14 != 0) {
    if (((uVar14 & 1) != 0) && ((bitsDamageType & 2U) != 0)) {
      fVar3 = flDamage * 0.5;
    }
    if (((uVar14 & 2) != 0) && ((bitsDamageType & 4U) != 0)) {
      fVar3 = fVar3 * 0.5;
    }
    if (((uVar14 & 4) != 0) && ((bitsDamageType & 0x40U) != 0)) {
      fVar3 = fVar3 * 0.5;
    }
    if (((uVar14 & 8) != 0) && ((bitsDamageType & 0x100U) != 0)) {
      fVar3 = fVar3 * 0.5;
    }
    if (((uVar14 & 0x10) != 0) && ((bitsDamageType & 8U) != 0)) {
      fVar3 = fVar3 * 0.5;
    }
  }
  pgVar17 = gpGlobals;
  if ((bitsDamageType & 0x8000000U) == 0) {
                    /* Unresolved local var: float flDmgSaved@[???]
                       Unresolved local var: float flArmorUsed@[???] */
    peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    fVar4 = ROUND(peVar16->armortype * fVar3);
    fVar5 = fVar4;
    if (bVar27) {
      BVar13 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pCVar10);
      if (BVar13 == 0) {
        peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
      }
      else if (pCVar10 == this) {
        peVar16 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev;
      }
      else if ((bitsDamageType & 0x40U) == 0) {
        if (((int)gpGlobals->teamplay & 0x100U) != 0) goto LAB_001105c8;
        if (((int)gpGlobals->teamplay & 0x80U) != 0) goto LAB_00110584;
LAB_001105b2:
        peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
      }
      else if (((int)gpGlobals->teamplay & 0x400U) == 0) {
        if (((int)gpGlobals->teamplay & 0x200U) == 0) goto LAB_001105b2;
LAB_00110584:
        peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        fVar5 = fVar4 * 0.5;
      }
      else {
LAB_001105c8:
        peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        fVar5 = 0.0;
      }
    }
    pgVar17 = gpGlobals;
    fVar28 = peVar16->armorvalue;
    fVar2 = fVar28;
    if (fVar28 <= fVar5) {
      fVar4 = peVar16->armortype * fVar28;
      peVar16->armortype = 0.0;
      peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.items;
      *piVar1 = *piVar1 & 0xffff1fff;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.armorclass = 0;
      fVar2 = peVar16->armorvalue;
      fVar5 = fVar28;
    }
    peVar16->armorvalue = fVar2 - fVar5;
    fVar3 = fVar3 - fVar4;
  }
  if (((((pevAttacker != pevInflictor) && (pevInflictor != (entvars_t *)0x0)) &&
       (local_90 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev, local_90->movetype == 3)) &&
      ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x10000) == 0 && (local_90->deadflag != 5)))) &&
     ((bitsDamageType & 4U) == 0)) {
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: int iMomentum@[???] */
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = flDamage / 20.0 + pgVar17->time;
    fVar4 = (local_90->origin).z - ((pevInflictor->absmin).z + (pevInflictor->absmax).z) * 0.5;
    fVar2 = (local_90->origin).y - ((pevInflictor->absmin).y + (pevInflictor->absmax).y) * 0.5;
    fVar6 = (local_90->origin).x - ((pevInflictor->absmin).x + (pevInflictor->absmax).x) * 0.5;
                    /* Unresolved local var: float flLen@[???] */
    fVar5 = fVar4 * fVar4 + fVar2 * fVar2 + fVar6 * fVar6;
    fVar28 = SQRT(fVar5);
    if (NAN(fVar28)) {
      fVar28 = sqrtf(fVar5);
      local_90 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      pgVar17 = gpGlobals;
    }
    fVar5 = 0.0;
    if (fVar28 == 0.0) {
      fVar4 = 1.0;
      fVar28 = fVar5;
    }
    else {
      fVar28 = 1.0 / fVar28;
      fVar4 = fVar4 * fVar28;
      fVar5 = fVar2 * fVar28;
      fVar28 = fVar28 * fVar6;
    }
    if (local_90->playerclass == 6) {
      if (flDamage <= 50.0) {
        local_48 = 0;
      }
      else {
        local_48 = local_48 / 4;
      }
    }
    if (((local_48 < 0x3c) && (bVar18)) && (pCVar10 != this)) {
      fVar2 = 11.0;
    }
    else {
      fVar2 = 8.0;
    }
    fVar6 = (float)local_48;
    (local_90->velocity).x = fVar28 * fVar6 * fVar2 + (local_90->velocity).x;
    (local_90->velocity).y = fVar5 * fVar6 * fVar2 + (local_90->velocity).y;
    (local_90->velocity).z = fVar4 * fVar6 * fVar2 + (local_90->velocity).z;
  }
  if (pgVar17->time <=
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.invincible_finished) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_fInvincSound < pgVar17->time) {
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                     "items/protect3.wav",1.0,0.8,0,100);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_fInvincSound = gpGlobals->time + 2.0;
    }
  }
  else if (((bitsDamageType & 0x10U) == 0) || (pCVar10 != this)) {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    fVar4 = (float)(int)ROUND(fVar3);
    iVar8 = CBaseMonster::TakeDamage
                      (&this->super_CBaseMonster,pevInflictor,pevAttacker,fVar4,bitsDamageType);
    gfPrototypeTotalDamage = fVar3 + gfPrototypeTotalDamage;
    if ((bVar27) &&
       (((BVar13 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pCVar10), BVar13 != 0 &&
         (pCVar10 != this)) &&
        (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->playerclass != 8)))) {
      uVar14 = (uint)gpGlobals->teamplay;
      if ((bitsDamageType & 0x40U) == 0) {
        if ((uVar14 & 0x1000) != 0) {
          peVar16 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
          (*(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0xd])(pCVar10,peVar16,peVar16,fVar4,0x8000000);
          goto LAB_0010fef4;
        }
        uVar14 = uVar14 & 0x800;
      }
      else {
        if ((uVar14 & 0x4000) != 0) {
          peVar16 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
          (*(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0xd])(pCVar10,peVar16,peVar16,fVar4,0x8000000);
          goto LAB_0010fef4;
        }
        uVar14 = uVar14 & 0x2000;
      }
      if (uVar14 != 0) {
        peVar16 = (pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev;
        (*(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0xd])
                  (pCVar10,peVar16,peVar16,(float)((int)ROUND(fVar3) / 2),0x8000000);
      }
    }
LAB_0010fef4:
                    /* Unresolved local var: int i@[???] */
    if ((bitsDamageType & 0x8000U) != 0) {
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[0] = '\0';
    }
    if ((bitsDamageType & 0x10000U) != 0) {
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[1] = '\0';
    }
    if ((bitsDamageType & 0x20000U) != 0) {
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[2] = '\0';
    }
    if ((bitsDamageType & 0x40000U) != 0) {
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[3] = '\0';
    }
    if ((bitsDamageType & 0x80000U) != 0) {
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[4] = '\0';
    }
    if ((bitsDamageType & 0x100000U) != 0) {
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[5] = '\0';
    }
    if ((bitsDamageType & 0x200000U) != 0) {
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[6] = '\0';
    }
    if ((bitsDamageType & 0x400000U) != 0) {
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[7] = '\0';
    }
    (*g_engfuncs.pfnMessageBegin)(9,0x33,(float *)0x0,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(9);
    (*g_engfuncs.pfnWriteByte)(2);
    p_Var7 = g_engfuncs.pfnWriteShort;
    iVar9 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var7)(iVar9);
    p_Var7 = g_engfuncs.pfnWriteShort;
    iVar9 = (*g_engfuncs.pfnIndexOfEdict)(pevInflictor->pContainingEntity);
    (*p_Var7)(iVar9);
    (*g_engfuncs.pfnWriteLong)(5);
    (*g_engfuncs.pfnMessageEnd)();
                    /* Unresolved local var: int i@[???] */
    if (0 < gpGlobals->maxClients) {
      iVar9 = 1;
      do {
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
        while ((pCVar10 = UTIL_PlayerByIndex(iVar9), pCVar10 == (CBasePlayer *)0x0 ||
               (pCVar11 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar10->m_hObserverTarget)
               , pCVar11 != this))) {
          iVar9 = iVar9 + 1;
          if (gpGlobals->maxClients < iVar9) goto LAB_001100bb;
        }
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgSpecHealth,(float *)0x0,
                   ((pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        fVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->health;
        iVar12 = 0;
        if (0.0 < fVar3) {
          iVar12 = (int)fVar3;
        }
        iVar9 = iVar9 + 1;
        (*g_engfuncs.pfnWriteByte)(iVar12);
        (*g_engfuncs.pfnMessageEnd)();
      } while (iVar9 <= gpGlobals->maxClients);
    }
LAB_001100bb:
    peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    bVar27 = true;
    piVar1 = &(this->super_CBaseMonster).m_bitsDamageType;
    *piVar1 = *piVar1 | bitsDamageType;
    this->m_bitsHUDDamage = -1;
    while (((bVar27 && (iVar8 != 0)) && (bitsDamageType != 0))) {
      bVar18 = (bitsDamageType & 0x80U) != 0;
      if (bVar18) {
        bitsDamageType = bitsDamageType & 0xffffff7f;
      }
      bVar19 = (bitsDamageType & 0x21U) != 0;
      if (bVar19) {
        bitsDamageType = bitsDamageType & 0xffffffde;
      }
      bVar20 = (bitsDamageType & 2U) != 0;
      if (bVar20) {
        bitsDamageType = bitsDamageType & 0xfffffffd;
      }
      bVar21 = (bitsDamageType & 4U) != 0;
      if (bVar21) {
        bitsDamageType = bitsDamageType & 0xfffffffb;
      }
      bVar22 = (bitsDamageType & 0x200U) != 0;
      if (bVar22) {
        bitsDamageType = bitsDamageType & 0xfffffdff;
      }
      bVar23 = (bitsDamageType & 0x28000U) != 0;
      if (bVar23) {
        bitsDamageType = bitsDamageType & 0xfffd7fff;
      }
      bVar24 = (bitsDamageType & 0x100000U) != 0;
      if (bVar24) {
        bitsDamageType = bitsDamageType & 0xffefffff;
      }
      bVar25 = (bitsDamageType & 0x10000U) != 0;
      if (bVar25) {
        bitsDamageType = bitsDamageType & 0xfffeffff;
      }
      bVar26 = (bitsDamageType & 0x40000U) != 0;
      if (bVar26) {
        bitsDamageType = bitsDamageType & 0xfffbffff;
      }
      bVar27 = (bitsDamageType & 0x100U) != 0;
      if (bVar27) {
        bitsDamageType = bitsDamageType & 0xfffffeff;
      }
      bVar27 = bVar27 || (bVar26 ||
                         (bVar25 ||
                         (bVar24 ||
                         (bVar23 || (bVar22 || (bVar21 || (bVar20 || (bVar19 || bVar18))))))));
      if (((bitsDamageType & 0x1000000U) != 0) && (peVar16->waterlevel < 2)) {
        Ignite(this,pevInflictor,pevAttacker);
        peVar16 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
      }
    }
    (peVar16->punchangle).x = -2.0;
    return iVar8;
  }
  return 0;
}


// CBasePlayer::PackDeadPlayerItems  @ 00109fa0  (line 1031)

/* DWARF original prototype: void PackDeadPlayerItems(CBasePlayer * this) */

void __thiscall CBasePlayer::PackDeadPlayerItems(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  CWeaponBox *this_00;
  CBasePlayerItem *pCVar9;
  int iVar10;
  CBasePlayer *pCVar11;
  int iVar12;
  globalvars_t *pgVar13;
  int *piVar14;
  BOOL in_stack_00000008;
  int local_f0 [33];
  CBasePlayerItem *local_6c;
  int local_68 [22];
  
                    /* Unresolved local var: int iWeaponRules@[???]
                       Unresolved local var: int iAmmoRules@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CBasePlayerWeapon *[20] rgpPackWeapons@[???]
                       Unresolved local var: int[33] iPackAmmo@[???]
                       Unresolved local var: int iPW@[???]
                       Unresolved local var: int iPA@[???]
                       Unresolved local var: CWeaponBox * pWeaponBox@[???] */
  uVar5 = 0;
  do {
    *(undefined4 *)((int)&local_6c + uVar5) = 0;
    *(undefined4 *)((int)local_68 + uVar5) = 0;
    *(undefined4 *)((int)local_68 + uVar5 + 4) = 0;
    *(undefined4 *)((int)local_68 + uVar5 + 8) = 0;
    uVar5 = uVar5 + 0x10;
  } while (uVar5 < 0x50);
  uVar5 = 0;
  do {
    uVar6 = uVar5;
    *(undefined4 *)((int)local_f0 + uVar6) = 0xffffffff;
    *(undefined4 *)((int)local_f0 + uVar6 + 4) = 0xffffffff;
    *(undefined4 *)((int)local_f0 + uVar6 + 8) = 0xffffffff;
    *(undefined4 *)((int)local_f0 + uVar6 + 0xc) = 0xffffffff;
    uVar5 = uVar6 + 0x10;
  } while (uVar6 + 0x10 < 0x80);
  *(undefined4 *)((int)local_f0 + uVar6 + 0x10) = 0xffffffff;
  if (cb_prematch_time + 3.0 <= gpGlobals->time) {
    iVar7 = (*g_pGameRules->_vptr_CGameRules[0x2f])(g_pGameRules,this);
    iVar8 = (*g_pGameRules->_vptr_CGameRules[0x30])(g_pGameRules,this);
    if ((iVar8 != 0xc) || (iVar7 != 9)) {
      iVar12 = 0;
      pCVar11 = this;
      do {
        pCVar9 = pCVar11->m_rgpPlayerItems[0];
        if (pCVar9 != (CBasePlayerItem *)0x0) {
          if (iVar7 == 7) {
            do {
              (&local_6c)[iVar12] = pCVar9;
              pCVar9 = pCVar9->m_pNext;
              iVar12 = iVar12 + 1;
            } while (pCVar9 != (CBasePlayerItem *)0x0);
          }
          else if (iVar7 == 8) {
            do {
              if ((this->m_pActiveItem != (CBasePlayerItem *)0x0) && (pCVar9 == this->m_pActiveItem)
                 ) {
                (&local_6c)[iVar12] = pCVar9;
                iVar12 = iVar12 + 1;
              }
              pCVar9 = pCVar9->m_pNext;
            } while (pCVar9 != (CBasePlayerItem *)0x0);
          }
          else {
            do {
                    /* Unresolved local var: CBasePlayerItem * pPlayerItem@[???] */
              pCVar9 = pCVar9->m_pNext;
            } while (pCVar9 != (CBasePlayerItem *)0x0);
          }
        }
        pCVar11 = (CBasePlayer *)
                  &(pCVar11->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
      } while (pCVar11 !=
               (CBasePlayer *)
               &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.m_pfnTouch);
      if (iVar8 != 0xc) {
        iVar7 = 0;
        iVar12 = 0;
        do {
          while (this->m_rgAmmo[iVar12] < 1) {
LAB_0010a0c9:
            iVar12 = iVar12 + 1;
            if (iVar12 == 0x20) goto LAB_0010a0ea;
          }
          if (iVar8 == 10) {
LAB_0010a0df:
            local_f0[iVar7] = iVar12;
          }
          else {
            if ((iVar8 != 0xb) || (pCVar9 = this->m_pActiveItem, pCVar9 == (CBasePlayerItem *)0x0))
            goto LAB_0010a0c9;
            iVar10 = (*(pCVar9->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                       _vptr_CBaseEntity[0x50])(pCVar9);
            if (iVar10 == iVar12) goto LAB_0010a0df;
            pCVar9 = this->m_pActiveItem;
            if ((pCVar9 == (CBasePlayerItem *)0x0) ||
               (iVar10 = (*(pCVar9->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                           _vptr_CBaseEntity[0x51])(pCVar9), iVar10 != iVar12)) goto LAB_0010a0c9;
            local_f0[iVar7] = iVar12;
          }
          iVar7 = iVar7 + 1;
          iVar12 = iVar12 + 1;
        } while (iVar12 != 0x20);
      }
LAB_0010a0ea:
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this_00 = (CWeaponBox *)
                CBaseEntity::Create("weaponbox",&peVar3->origin,&peVar3->angles,
                                    peVar3->pContainingEntity);
      pgVar13 = gpGlobals;
      (((this_00->super_CBaseEntity).pev)->angles).x = 0.0;
      (((this_00->super_CBaseEntity).pev)->angles).z = 0.0;
      (this_00->super_CBaseEntity).m_pfnThink.__pfn = CWeaponBox::Kill;
      peVar3 = (this_00->super_CBaseEntity).pev;
      (this_00->super_CBaseEntity).m_pfnThink.__delta = 0;
      peVar3->nextthink = pgVar13->time + 120.0;
      if (local_f0[0] != -1) {
        piVar14 = local_f0;
        do {
          piVar14 = piVar14 + 1;
          CWeaponBox::PackAmmo
                    (this_00,(int)CBasePlayerItem::AmmoInfoArray[local_f0[0]].pszName -
                             (int)pgVar13->pStringBase,this->m_rgAmmo[local_f0[0]]);
          local_f0[0] = *piVar14;
          pgVar13 = gpGlobals;
        } while (local_f0[0] != -1);
      }
      if (local_6c != (CBasePlayerItem *)0x0) {
        piVar14 = local_68;
        do {
          CWeaponBox::PackWeapon(this_00,local_6c);
          local_6c = (CBasePlayerItem *)*piVar14;
          piVar14 = piVar14 + 1;
        } while (local_6c != (CBasePlayerItem *)0x0);
      }
      if (iVar8 != 0xc) {
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
    }
  }
  RemoveAllItems(this,in_stack_00000008);
  return;
}


// CBasePlayer::RemoveAllItems  @ 00109cd0  (line 1173)

/* DWARF original prototype: void RemoveAllItems(CBasePlayer * this, BOOL removeSuit) */

void __thiscall CBasePlayer::RemoveAllItems(CBasePlayer *this,BOOL removeSuit)

{
  EHANDLE *this_00;
  CBasePlayerItem *pCVar1;
  CBasePlayerItem *pCVar2;
  entvars_t *peVar3;
  CBasePlayer *in_EAX;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  CBaseEntity *pCVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  CBasePlayer *pCVar12;
  uint uVar13;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBasePlayerItem * pPendingItem@[???] */
  if (in_EAX->m_pActiveItem != (CBasePlayerItem *)0x0) {
    if (((in_EAX->m_vecAutoAim).x != 0.0) || ((in_EAX->m_vecAutoAim).y != 0.0)) {
      peVar3 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (in_EAX->m_vecAutoAim).x = 0.0;
      (in_EAX->m_vecAutoAim).y = 0.0;
      (in_EAX->m_vecAutoAim).z = 0.0;
      (*g_engfuncs.pfnCrosshairAngle)(peVar3->pContainingEntity,0.0,0.0);
    }
    in_EAX->m_fOnTarget = 0;
    (*(in_EAX->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x49])(in_EAX->m_pActiveItem,0);
    in_EAX->m_pActiveItem = (CBasePlayerItem *)0x0;
  }
  pCVar1 = in_EAX->m_pLastItem;
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    pcVar4 = (char *)(*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                       _vptr_CBaseEntity[0x29])(pCVar1);
    in_EAX->m_pszLastItem = pcVar4;
  }
  in_EAX->m_pLastItem = (CBasePlayerItem *)0x0;
  this_00 = &in_EAX->m_pTank;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pCVar7 = EHANDLE::operator->(this_00);
    (*pCVar7->_vptr_CBaseEntity[0x2d])(pCVar7);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  pCVar12 = in_EAX;
  do {
    pCVar1 = pCVar12->m_rgpPlayerItems[0];
    in_EAX->m_pActiveItem = pCVar1;
    while (pCVar1 != (CBasePlayerItem *)0x0) {
      pCVar2 = pCVar1->m_pNext;
      (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4d])
                (pCVar1);
      in_EAX->m_pActiveItem = pCVar2;
      pCVar1 = pCVar2;
    }
    pCVar12->m_rgpPlayerItems[0] = (CBasePlayerItem *)0x0;
    pCVar12 = (CBasePlayer *)
              &(pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
  } while (pCVar12 !=
           (CBasePlayer *)
           &(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_pfnTouch);
  peVar3 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  in_EAX->m_pActiveItem = (CBasePlayerItem *)0x0;
  peVar3->viewmodel = 0;
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->weaponmodel = 0;
  piVar8 = &((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weapons;
  *piVar8 = *piVar8 & 0x80000000;
  uVar9 = -(((uint)in_EAX->m_rgAmmo & 0xf) >> 2) & 3;
  if (uVar9 == 0) {
    iVar5 = 0x20;
    uVar6 = 0;
  }
  else {
    uVar6 = 0;
    do {
      in_EAX->m_rgAmmo[uVar6] = 0;
      uVar6 = uVar6 + 1;
      iVar5 = 0x20 - uVar6;
    } while (uVar6 < uVar9);
  }
  uVar13 = 0x20 - uVar9 >> 2;
  if (uVar13 != 0) {
    piVar8 = in_EAX->m_rgAmmo + uVar9;
    uVar10 = 0;
    do {
      uVar10 = uVar10 + 1;
      piVar8[0] = 0;
      piVar8[1] = 0;
      piVar8[2] = 0;
      piVar8[3] = 0;
      piVar8 = piVar8 + 4;
    } while (uVar10 < uVar13);
    uVar6 = uVar6 + uVar13 * 4;
    iVar5 = iVar5 + uVar13 * -4;
    if (0x20 - uVar9 == uVar13 * 4) goto LAB_00109ed0;
  }
  iVar11 = 0;
  do {
    *(undefined4 *)((int)in_EAX->m_rgAmmo + iVar11 + uVar6 * 4) = 0;
    iVar11 = iVar11 + 4;
  } while (iVar11 != iVar5 * 4);
LAB_00109ed0:
  UpdateClientData(in_EAX);
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgCurWeapon,(float *)0x0,
             ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x00109f34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::RemoveAllItems  @ 001099d0  (line 1174)

/* DWARF original prototype: void RemoveAllItems(CBasePlayer * this, BOOL removeSuit) */

void __thiscall CBasePlayer::RemoveAllItems(CBasePlayer *this,BOOL removeSuit)

{
  EHANDLE *this_00;
  CBasePlayerItem *pCVar1;
  CBasePlayerItem *pCVar2;
  entvars_t *peVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  CBaseEntity *pCVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  CBasePlayer *pCVar12;
  uint uVar13;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBasePlayerItem * pPendingItem@[???] */
  if (this->m_pActiveItem != (CBasePlayerItem *)0x0) {
    if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
      (this->m_vecAutoAim).x = 0.0;
      (this->m_vecAutoAim).y = 0.0;
      (this->m_vecAutoAim).z = 0.0;
      (*g_engfuncs.pfnCrosshairAngle)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
    }
    this->m_fOnTarget = 0;
    (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x49])(this->m_pActiveItem,0);
    this->m_pActiveItem = (CBasePlayerItem *)0x0;
  }
  pCVar1 = this->m_pLastItem;
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    pcVar4 = (char *)(*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                       _vptr_CBaseEntity[0x29])(pCVar1);
    this->m_pszLastItem = pcVar4;
  }
  this->m_pLastItem = (CBasePlayerItem *)0x0;
  this_00 = &this->m_pTank;
  iVar5 = EHANDLE::operator_int(this_00);
  if (iVar5 != 0) {
    pCVar7 = EHANDLE::operator->(this_00);
    (*pCVar7->_vptr_CBaseEntity[0x2d])(pCVar7,this,this,0,0);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  pCVar12 = this;
  do {
    pCVar1 = pCVar12->m_rgpPlayerItems[0];
    this->m_pActiveItem = pCVar1;
    while (pCVar1 != (CBasePlayerItem *)0x0) {
      pCVar2 = pCVar1->m_pNext;
      (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4d])
                (pCVar1);
      this->m_pActiveItem = pCVar2;
      pCVar1 = pCVar2;
    }
    pCVar12->m_rgpPlayerItems[0] = (CBasePlayerItem *)0x0;
    pCVar12 = (CBasePlayer *)
              &(pCVar12->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
               .super_CBaseEntity.pev;
  } while (pCVar12 !=
           (CBasePlayer *)
           &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_pfnTouch);
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_pActiveItem = (CBasePlayerItem *)0x0;
  peVar3->viewmodel = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->weaponmodel = 0;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (removeSuit == 0) {
    piVar8 = &peVar3->weapons;
    *piVar8 = *piVar8 & 0x80000000;
  }
  else {
    peVar3->weapons = 0;
  }
  uVar9 = -(((uint)this->m_rgAmmo & 0xf) >> 2) & 3;
  if (uVar9 == 0) {
    iVar5 = 0x20;
    uVar6 = 0;
  }
  else {
    uVar6 = 0;
    do {
      this->m_rgAmmo[uVar6] = 0;
      uVar6 = uVar6 + 1;
      iVar5 = 0x20 - uVar6;
    } while (uVar6 < uVar9);
  }
  uVar13 = 0x20 - uVar9 >> 2;
  if (uVar13 != 0) {
    piVar8 = this->m_rgAmmo + uVar9;
    uVar10 = 0;
    do {
      uVar10 = uVar10 + 1;
      piVar8[0] = 0;
      piVar8[1] = 0;
      piVar8[2] = 0;
      piVar8[3] = 0;
      piVar8 = piVar8 + 4;
    } while (uVar10 < uVar13);
    uVar6 = uVar6 + uVar13 * 4;
    iVar5 = iVar5 + uVar13 * -4;
    if (0x20 - uVar9 == uVar13 * 4) goto LAB_00109bf0;
  }
  iVar11 = 0;
  do {
    *(undefined4 *)((int)this->m_rgAmmo + iVar11 + uVar6 * 4) = 0;
    iVar11 = iVar11 + 4;
  } while (iVar11 != iVar5 * 4);
LAB_00109bf0:
  UpdateClientData(this);
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgCurWeapon,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0);
                    /* WARNING: Could not recover jumptable at 0x00109c54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::Killed  @ 00111eb0  (line 1237)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CBasePlayer * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CBasePlayer::Killed(CBasePlayer *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  EHANDLE *this_00;
  int *piVar1;
  float fVar2;
  CBasePlayerItem *pCVar3;
  ULONG UVar4;
  _func_void_int *p_Var5;
  uint uVar6;
  int iVar7;
  CSound *this_01;
  globalvars_t *pgVar8;
  CBaseEntity *pCVar9;
  edict_t *peVar10;
  void *pvVar11;
  entvars_t *peVar12;
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
  pCVar3 = this->m_pActiveItem;
  if (pCVar3 != (CBasePlayerItem *)0x0) {
    (*(pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar3,0);
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
  UVar4 = g_ulModelIndexPlayer;
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
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
  peVar12->modelindex = UVar4;
  if (this->m_iBeingTeleported != 0) {
    PlayerStoppedTeleporting(this);
  }
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
  if (((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x10) != 0) &&
      (peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev, peVar12->enemy == peVar12->pContainingEntity)) &&
     (pCVar9 = CBaseEntity::FindTimer((CBaseEntity *)this,2), pCVar9 != (CBaseEntity *)0x0)) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
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
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffbfe;
  peVar12->deadflag = 1;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 6;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  fVar2 = (peVar12->velocity).z;
  if (fVar2 < 10.0) {
    (*g_engfuncs.pfnRandomFloat)(0.0,300.0);
    (peVar12->velocity).z = (float)((longdouble)fVar2 + extraout_ST0);
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    iVar7 = peVar12->weapons;
  }
  else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
    iVar7 = peVar12->weapons;
  }
  if (iVar7 < 0) {
    iVar7 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar7 == 0) {
      this->m_rgSuitPlayList[0] = 0;
      this->m_rgSuitPlayList[1] = 0;
      this->m_rgSuitPlayList[2] = 0;
      this->m_rgSuitPlayList[3] = 0;
    }
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
  }
  this->m_iClientHealth = 0;
  (*g_engfuncs.pfnMessageBegin)(1,gmsgHealth,(float *)0x0,peVar12->pContainingEntity);
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
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if (((iGib != 1) && (peVar12->health < -40.0)) || (iGib == 2)) {
    peVar12->solid = 0;
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x7b])(this);
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 | 0x80;
    pgVar8 = gpGlobals;
  }
  else {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x81])(this);
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_detpacking = 0;
    (peVar12->angles).x = 0.0;
    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev)->angles).z = 0.0;
    pgVar8 = gpGlobals;
    this->m_iRespawnFrames = 0.0;
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__pfn = PlayerDeathThink;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_pfnThink.__delta = 0;
    peVar12->nextthink = pgVar8->time + 0.1;
  }
                    /* Unresolved local var: float flRestime@[???] */
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.respawn_time <= pgVar8->time) {
    TeamFortress_SetupRespawn(this,(BOOL)pevInflictor);
    return;
  }
  return;
}


// CBasePlayer::SetAnimation  @ 00102aa0  (line 1430)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetAnimation(CBasePlayer * this, PLAYER_ANIM playerAnim) */

void __thiscall CBasePlayer::SetAnimation(CBasePlayer *this,PLAYER_ANIM playerAnim)

{
  int *piVar1;
  float fVar2;
  byte bVar3;
  _func_int_varargs **pp_Var4;
  int32 iVar5;
  int iVar6;
  Activity AVar7;
  int iVar8;
  entvars_t *peVar9;
  Activity activity;
  float fVar10;
  char local_5c [76];
  
                    /* Unresolved local var: int animDesired@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: char[64] szAnim@[???]
                       Unresolved local var: int newAnimState@[???] */
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar2 = (peVar9->velocity).x;
  fVar10 = (peVar9->velocity).y;
  fVar2 = fVar10 * fVar10 + fVar2 * fVar2;
  fVar10 = SQRT(fVar2);
  if (NAN(fVar10)) {
    fVar10 = sqrtf(fVar2);
    peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if ((peVar9->flags & 0x1000U) != 0) {
    fVar10 = 0.0;
switchD_00102b68_caseD_0:
    AVar7 = (this->super_CBaseMonster).m_Activity;
    if (((peVar9->flags & 0x200U) == 0) && (AVar7 - ACT_HOP < 2)) {
      (this->super_CBaseMonster).m_IdealActivity = AVar7;
      activity = AVar7;
      goto joined_r0x00102d89;
    }
    if (1 < peVar9->waterlevel) {
      if (fVar10 == 0.0) {
        (this->super_CBaseMonster).m_IdealActivity = ACT_HOVER;
        activity = ACT_HOVER;
      }
      else {
        (this->super_CBaseMonster).m_IdealActivity = ACT_SWIM;
        activity = ACT_SWIM;
      }
      goto LAB_00102e9d;
    }
    (this->super_CBaseMonster).m_IdealActivity = ACT_WALK;
    goto LAB_00102d98;
  }
  switch(playerAnim) {
  case PLAYER_IDLE:
  case PLAYER_WALK:
    goto switchD_00102b68_caseD_0;
  case PLAYER_JUMP:
    AVar7 = (this->super_CBaseMonster).m_Activity;
    (this->super_CBaseMonster).m_IdealActivity = ACT_HOP;
    activity = ACT_HOP;
    goto LAB_00102e9d;
  case PLAYER_SUPERJUMP:
    AVar7 = (this->super_CBaseMonster).m_Activity;
    (this->super_CBaseMonster).m_IdealActivity = ACT_LEAP;
    activity = ACT_LEAP;
    goto LAB_00102e9d;
  case PLAYER_DIE:
    pp_Var4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
    (this->super_CBaseMonster).m_IdealActivity = ACT_DIESIMPLE;
    activity = (*pp_Var4[0x7a])(this);
    (this->super_CBaseMonster).m_IdealActivity = activity;
    goto joined_r0x00102d89;
  case PLAYER_ATTACK1:
    activity = (this->super_CBaseMonster).m_Activity;
    if (activity == ACT_DIESIMPLE) {
LAB_00102f40:
      (this->super_CBaseMonster).m_IdealActivity = activity;
      goto joined_r0x00102d89;
    }
    if ((int)activity < 0x25) {
      if (activity - ACT_SWIM < 3) goto LAB_00102f40;
    }
    else if (activity == ACT_HOVER) goto LAB_00102f40;
    (this->super_CBaseMonster).m_IdealActivity = ACT_RANGE_ATTACK1;
    goto LAB_00102c2e;
  case PLAYER_FEIGN:
    iVar5 = (*g_engfuncs.pfnRandomLong)(0,7);
    switch(iVar5) {
    case 0:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIESIMPLE;
      iVar8 = 0x24;
      break;
    case 1:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIEBACKWARD;
      iVar8 = 0x25;
      break;
    case 2:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIEFORWARD;
      iVar8 = 0x26;
      break;
    case 3:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIEVIOLENT;
      iVar8 = 0x27;
      break;
    case 4:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIE_HEADSHOT;
      iVar8 = 0x42;
      break;
    case 5:
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIE_CHESTSHOT;
      iVar8 = 0x43;
      break;
    case 6:
      iVar8 = 0x44;
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIE_GUTSHOT;
      break;
    default:
      iVar8 = 0x45;
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIE_BACKSHOT;
    }
    iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,iVar8);
    if (iVar8 == -1) {
      AVar7 = (this->super_CBaseMonster).m_Activity;
      (this->super_CBaseMonster).m_IdealActivity = ACT_DIESIMPLE;
      activity = ACT_DIESIMPLE;
      goto LAB_00102e9d;
    }
  }
  activity = (this->super_CBaseMonster).m_IdealActivity;
joined_r0x00102d89:
  if (activity == ACT_WALK) {
    peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    AVar7 = (this->super_CBaseMonster).m_Activity;
LAB_00102d98:
    if ((AVar7 != ACT_RANGE_ATTACK1) ||
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished != 0))
    {
      if ((peVar9->playerclass == 2) &&
         (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.tfstate & 0x800) != 0)) {
        iVar8 = 6 - (uint)((peVar9->flags & 0x4000U) == 0);
      }
      else {
        iVar8 = 2 - (uint)((peVar9->flags & 0x4000U) == 0);
      }
      if ((this->m_iCurrentAnimationState != iVar8) ||
         (iVar6 = this->m_iCurrentAnimationSequence, iVar6 == 0)) {
        sprintf(local_5c,g_PlayerAnimationNames[iVar8],this->m_szAnimExtention);
        iVar6 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,local_5c);
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        this->m_iCurrentAnimationState = iVar8;
        this->m_iCurrentAnimationSequence = iVar6;
      }
      (this->super_CBaseMonster).m_Activity = ACT_WALK;
      if (iVar6 == -1) {
        iVar6 = 0;
      }
      bVar3 = *(byte *)((int)&peVar9->flags + 1);
      goto joined_r0x00102cfd;
    }
    iVar6 = peVar9->sequence;
  }
  else {
    if (activity != ACT_RANGE_ATTACK1) {
      AVar7 = (this->super_CBaseMonster).m_Activity;
LAB_00102e9d:
      if (activity != AVar7) {
        (this->super_CBaseMonster).m_Activity = activity;
        iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,activity);
        peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (peVar9->sequence != iVar8) {
          peVar9->gaitsequence = 0;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->sequence = iVar8;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->frame = 0.0;
          CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
        }
      }
      return;
    }
    peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
LAB_00102c2e:
    iVar8 = 4 - (uint)((peVar9->flags & 0x4000U) == 0);
    if ((this->m_iCurrentAnimationState != iVar8) ||
       (iVar6 = this->m_iCurrentAnimationSequence, iVar6 == 0)) {
      sprintf(local_5c,g_PlayerAnimationNames[iVar8],this->m_szAnimExtention);
      iVar6 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,local_5c);
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_iCurrentAnimationState = iVar8;
      this->m_iCurrentAnimationSequence = iVar6;
    }
    if (iVar6 == -1) {
      iVar6 = 0;
    }
    if ((peVar9->sequence != iVar6) ||
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceLoops == 0)) {
      peVar9->frame = 0.0;
      if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceLoops == 0) {
        piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->effects;
        *piVar1 = *piVar1 | 0x20;
      }
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    (this->super_CBaseMonster).m_Activity = (this->super_CBaseMonster).m_IdealActivity;
    peVar9->sequence = iVar6;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  bVar3 = *(byte *)((int)&peVar9->flags + 1);
joined_r0x00102cfd:
  if ((bVar3 & 0x40) == 0) {
    if (220.0 < fVar10) {
      iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,4);
      *(int *)((int)peVar9 + 300) = iVar8;
    }
    else if (fVar10 <= 0.0) {
      iVar8 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,"deep_idle");
      *(int *)((int)peVar9 + 300) = iVar8;
    }
    else {
      iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,3);
      *(int *)((int)peVar9 + 300) = iVar8;
    }
  }
  else if (fVar10 == 0.0) {
    iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x12);
    *(int *)((int)peVar9 + 300) = iVar8;
  }
  else {
    iVar8 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,0x11);
    *(int *)((int)peVar9 + 300) = iVar8;
  }
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar9->sequence != iVar6) {
    peVar9->sequence = iVar6;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->frame = 0.0;
    CBaseAnimating::ResetSequenceInfo((CBaseAnimating *)this);
    return;
  }
  return;
}


// CBasePlayer::WaterMove  @ 00103770  (line 1677)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void WaterMove(CBasePlayer * this) */

void __thiscall CBasePlayer::WaterMove(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int32 iVar4;
  int iVar5;
  edict_t *peVar6;
  globalvars_t *pgVar7;
  entvars_t *peVar8;
  entvars_t *peVar9;
  _func_int_varargs *p_Var10;
  char *pcVar11;
  undefined4 uVar12;
  float local_3c;
  
                    /* Unresolved local var: int air@[???] */
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar8->movetype == 0) {
    return;
  }
  if (peVar8->movetype == 8) {
    return;
  }
  if (peVar8->health < 0.0) {
    return;
  }
  if (peVar8->waterlevel == 3) {
    uVar3 = (this->super_CBaseMonster).m_bitsDamageType;
    (this->super_CBaseMonster).m_rgbTimeBasedDamage[4] = '\0';
    (this->super_CBaseMonster).m_bitsDamageType = uVar3 & 0xfff7ffff;
    pgVar7 = gpGlobals;
    if (gpGlobals->time <= peVar8->air_finished) {
      (this->super_CBaseMonster).m_bitsDamageType = uVar3 & 0xfff7bfff;
    }
    else if (peVar8->pain_finished < gpGlobals->time) {
      peVar8->dmg = peVar8->dmg + 1.0;
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar1 = peVar8->dmg;
      if (5.0 < fVar1) {
        peVar8->dmg = 5.0;
        fVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->dmg;
      }
      p_Var10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0xd];
      peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar8 = &peVar6->v;
      if (peVar6 == (edict_t *)0x0) {
        peVar8 = (entvars_t *)0x0;
      }
      peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar9 = (entvars_t *)0x0;
      if (peVar6 != (edict_t *)0x0) {
        peVar9 = &peVar6->v;
      }
      (*p_Var10)(this,peVar9,peVar8,fVar1,0x8004000);
      pgVar7 = gpGlobals;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->pain_finished = gpGlobals->time + 1.0;
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_idrowndmg = (int)((float)this->m_idrowndmg + peVar8->dmg);
    }
  }
  else {
    fVar1 = gpGlobals->time;
    if (peVar8->air_finished < fVar1) {
      pcVar11 = "player/pl_wade1.wav";
LAB_001038a4:
      EMIT_SOUND_DYN(peVar8->pContainingEntity,2,pcVar11,1.0,0.8,0,100);
      peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar1 = gpGlobals->time;
    }
    else if (peVar8->air_finished < fVar1 + 9.0) {
      pcVar11 = "player/pl_wade2.wav";
      goto LAB_001038a4;
    }
    pgVar7 = gpGlobals;
    peVar8->air_finished = fVar1 + 12.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmg = 2.0;
    if (this->m_idrownrestored < this->m_idrowndmg) {
      uVar3 = (this->super_CBaseMonster).m_bitsDamageType;
      (this->super_CBaseMonster).m_rgbTimeBasedDamage[4] = '\0';
      (this->super_CBaseMonster).m_bitsDamageType = uVar3 & 0xffffbfff | 0x80000;
    }
    peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar8->waterlevel == 0) {
    if ((peVar8->flags & 0x10U) == 0) {
      return;
    }
    peVar8->flags = peVar8->flags & 0xffffffef;
    return;
  }
  fVar1 = peVar8->air_finished;
  fVar2 = pgVar7->time;
  iVar4 = (*g_engfuncs.pfnRandomLong)(0,0x1f);
  if ((iVar4 == 0) && (iVar4 = (*g_engfuncs.pfnRandomLong)(0,0xb), (int)(fVar1 - fVar2) <= iVar4)) {
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
    if (iVar4 == 1) {
      pcVar11 = "player/pl_swim2.wav";
    }
    else if (iVar4 < 2) {
      if (iVar4 != 0) goto LAB_001038fe;
      pcVar11 = "player/pl_swim1.wav";
    }
    else if (iVar4 == 2) {
      pcVar11 = "player/pl_swim3.wav";
    }
    else {
      if (iVar4 != 3) goto LAB_001038fe;
      pcVar11 = "player/pl_swim4.wav";
    }
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,4,pcVar11,0.8,0.8,0,
                   100);
  }
LAB_001038fe:
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar8->watertype == -5) {
    if (gpGlobals->time <= peVar8->dmgtime) goto LAB_00103919;
    iVar5 = peVar8->waterlevel * 10;
    p_Var10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0xd];
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar8 = &peVar6->v;
    if (peVar6 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar9 = (entvars_t *)0x0;
    if (peVar6 != (edict_t *)0x0) {
      peVar9 = &peVar6->v;
    }
    uVar12 = 8;
  }
  else {
    if (peVar8->watertype != -4) goto LAB_00103919;
    peVar8->dmgtime = gpGlobals->time + 1.0;
    p_Var10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0xd];
    iVar5 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->waterlevel << 2;
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar8 = &peVar6->v;
    if (peVar6 == (edict_t *)0x0) {
      peVar8 = (entvars_t *)0x0;
    }
    peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar9 = (entvars_t *)0x0;
    if (peVar6 != (edict_t *)0x0) {
      peVar9 = &peVar6->v;
    }
    uVar12 = 0x100000;
  }
  local_3c = (float)iVar5;
  (*p_Var10)(this,peVar9,peVar8,local_3c,uVar12);
  peVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
LAB_00103919:
  if ((peVar8->flags & 0x10U) == 0) {
    peVar8->flags = peVar8->flags | 0x10;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmgtime = 0.0;
  }
  return;
}


// CBasePlayer::IsOnLadder  @ 00103cf0  (line 1817)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL IsOnLadder(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::IsOnLadder(CBasePlayer *this)

{
  return (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->movetype == 5);
}


// CBasePlayer::PlayerDeathThink  @ 0010a2f0  (line 1821)

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
    if (0.0 < fVar7) {
                    /* Unresolved local var: float flLen@[???] */
      fVar8 = (peVar4->velocity).x;
      fVar2 = (peVar4->velocity).y;
      fVar3 = (peVar4->velocity).z;
      fVar2 = fVar3 * fVar3 + fVar2 * fVar2 + fVar8 * fVar8;
      fVar8 = SQRT(fVar2);
      if (NAN(fVar8)) {
        fVar8 = sqrtf(fVar2);
      }
      fVar2 = 0.0;
      if (fVar8 == 0.0) {
        fVar3 = 1.0;
        fVar8 = fVar2;
      }
      else {
        fVar8 = 1.0 / fVar8;
        fVar3 = (peVar4->velocity).z * fVar8;
        fVar2 = fVar8 * (peVar4->velocity).x;
        fVar8 = (peVar4->velocity).y * fVar8;
      }
      (peVar4->velocity).x = fVar2 * fVar7;
      (peVar4->velocity).y = fVar8 * fVar7;
      (peVar4->velocity).z = fVar3 * fVar7;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    else {
      (peVar4->velocity).x = g_vecZero.x;
      (peVar4->velocity).y = g_vecZero.y;
      (peVar4->velocity).z = g_vecZero.z;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
  }
  if (((peVar4->modelindex != 0) &&
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.m_fSequenceFinished == 0))
     && ((peVar4->deadflag == 5 || (peVar4->deadflag == 1)))) {
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
    if ((((((this->m_rgpPlayerItems[0] != (CBasePlayerItem *)0x0) ||
           (this->m_rgpPlayerItems[1] != (CBasePlayerItem *)0x0)) ||
          (this->m_rgpPlayerItems[2] != (CBasePlayerItem *)0x0)) ||
         ((this->m_rgpPlayerItems[3] != (CBasePlayerItem *)0x0 ||
          (this->m_rgpPlayerItems[4] != (CBasePlayerItem *)0x0)))) ||
        (this->m_rgpPlayerItems[5] != (CBasePlayerItem *)0x0)) &&
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
          this->m_fDeadTime = gpGlobals->time;
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->deadflag = 3;
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


// CBasePlayer::StartDeathCam  @ 00111a70  (line 1928)

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
  CBasePlayer *pCVar6;
  char *pcVar7;
  Vector *vec;
  char *pcVar8;
  undefined4 uVar9;
  vec_t in_stack_ffffff60;
  vec_t in_stack_ffffff64;
  TraceResult *ptr;
  undefined8 in_stack_ffffff68;
  TraceResult local_8c;
  vec_t local_54;
  vec_t local_50;
  vec_t local_4c;
  vec_t local_48;
  vec_t local_44;
  vec_t local_40;
  Vector local_3c;
  Vector local_30 [2];
  float local_18;
  float local_14;
  float fStack_10;
  
                    /* Unresolved local var: edict_t * pSpot@[???]
                       Unresolved local var: edict_t * pNewSpot@[DW_OP_reg0(EAX)]
                       Unresolved local var: int iRand@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((((peVar1->view_ofs).x != g_vecZero.x) || ((peVar1->view_ofs).y != g_vecZero.y)) ||
     ((peVar1->view_ofs).z != g_vecZero.z)) {
    pcVar8 = "info_intermission";
    peVar2 = (*g_engfuncs.pfnFindEntityByString)((edict_t *)0x0,"classname","info_intermission");
    if ((peVar2 == (edict_t *)0x0) ||
       (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2), iVar3 == 0)) {
                    /* Unresolved local var: TraceResult tr@[???] */
      pCVar6 = (CBasePlayer *)(local_30 + 1);
      CopyToBodyQue((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev);
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      ptr = &local_8c;
      peVar2 = peVar1->pContainingEntity;
      local_3c.z = (peVar1->origin).z + 128.0;
      local_3c.y = (peVar1->origin).y + 0.0;
      local_3c.x = (peVar1->origin).x + 0.0;
      uVar9 = 1;
      UTIL_TraceLine(&peVar1->origin,&local_3c,ignore_monsters,peVar2,ptr);
      peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      local_30[0].z = local_8c.vecEndPos.z - (peVar1->origin).z;
      local_30[0].y = local_8c.vecEndPos.y - (peVar1->origin).y;
      local_30[0].x = local_8c.vecEndPos.x - (peVar1->origin).x;
      vec = local_30;
      UTIL_VecToAngles((Vector *)pCVar6,vec);
      local_18 = local_8c.vecEndPos.x;
      local_14 = local_8c.vecEndPos.y;
      fStack_10 = local_8c.vecEndPos.z;
      vecPosition_00.y = (vec_t)uVar9;
      vecPosition_00.x = (vec_t)vec;
      vecPosition_00.z = (vec_t)peVar2;
      vecViewAngle_00.y = (vec_t)(int)in_stack_ffffff68;
      vecViewAngle_00.z = (vec_t)(int)((ulonglong)in_stack_ffffff68 >> 0x20);
      vecViewAngle_00.x = (vec_t)ptr;
      StartObserver(pCVar6,vecPosition_00,vecViewAngle_00);
      return;
    }
    pcVar7 = (char *)0x3;
    iVar4 = (*g_engfuncs.pfnRandomLong)(0,3);
    if (0 < iVar4) {
      do {
        pcVar8 = "info_intermission";
        pcVar7 = "classname";
        peVar5 = (*g_engfuncs.pfnFindEntityByString)(peVar2,"classname","info_intermission");
        if (peVar5 != (edict_t *)0x0) {
          peVar2 = peVar5;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    pCVar6 = (CBasePlayer *)
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    CopyToBodyQue((entvars_t *)pCVar6);
    local_48 = (peVar2->v).v_angle.x;
    local_44 = (peVar2->v).v_angle.y;
    local_40 = (peVar2->v).v_angle.z;
    local_54 = (peVar2->v).origin.x;
    local_50 = (peVar2->v).origin.y;
    local_4c = (peVar2->v).origin.z;
    vecPosition.y = (vec_t)pcVar8;
    vecPosition.x = (vec_t)pcVar7;
    vecPosition.z = in_stack_ffffff60;
    vecViewAngle.y = (vec_t)(int)in_stack_ffffff68;
    vecViewAngle.z = (vec_t)(int)((ulonglong)in_stack_ffffff68 >> 0x20);
    vecViewAngle.x = in_stack_ffffff64;
    StartObserver(pCVar6,vecPosition,vecViewAngle);
  }
  return;
}


// CBasePlayer::StartObserver  @ 00111540  (line 1971)

/* DWARF original prototype: void StartObserver(CBasePlayer * this, Vector vecPosition, Vector
   vecViewAngle) */

void __thiscall CBasePlayer::StartObserver(CBasePlayer *this,Vector vecPosition,Vector vecViewAngle)

{
  EHANDLE *this_00;
  int *piVar1;
  CBasePlayerItem *pCVar2;
  int iVar3;
  _func_void_int *p_Var4;
  CBasePlayer *in_EAX;
  uint uVar5;
  int iVar6;
  entvars_t *peVar7;
  CBaseEntity *pCVar8;
  edict_t *peVar9;
  void *pvVar10;
  vec_t *in_ECX;
  Vector *in_EDX;
  CBasePlayer *this_01;
  BOOL removeSuit;
  
                    /* Unresolved local var: int iOldTeam@[???] */
  (*g_engfuncs.pfnMessageBegin)
            (5,0x17,&(((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x7d);
  p_Var4 = g_engfuncs.pfnWriteByte;
  uVar5 = (*g_engfuncs.pfnIndexOfEdict)
                    (((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(uVar5 & 0xff);
  (*g_engfuncs.pfnMessageEnd)();
  pCVar2 = in_EAX->m_pActiveItem;
  if (pCVar2 != (CBasePlayerItem *)0x0) {
    (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar2,0);
  }
  this_00 = &in_EAX->m_pTank;
  iVar6 = EHANDLE::operator_int(this_00);
  if (iVar6 != 0) {
    pCVar8 = EHANDLE::operator->(this_00);
    (*pCVar8->_vptr_CBaseEntity[0x2d])(pCVar8);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  if (in_EAX->m_iBeingTeleported != 0) {
    PlayerStoppedTeleporting(in_EAX);
  }
  TeleporterResetEffects(in_EAX);
  iVar6 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = 0;
  peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invisible_finished = 0.0;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invincible_finished = 0.0;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.super_damage_finished = 0.0;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.radsuit_finished = 0.0;
  if (((iVar6 & 0x10) == 0) || (peVar7->pContainingEntity != peVar7->enemy)) {
LAB_0011163b:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
    iVar6 = peVar7->weapons;
  }
  else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar8 = CBaseEntity::FindTimer((CBaseEntity *)in_EAX,2);
    if (pCVar8 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
      peVar9 = pCVar8->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar9 == (edict_t *)0x0) &&
         (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
        pvVar10 = (void *)0x0;
      }
      else {
        pvVar10 = peVar9->pvPrivateData;
      }
      iVar6 = *(int *)((int)pvVar10 + 0x144) + 1;
      *(int *)((int)pvVar10 + 0x144) = iVar6;
      if (*(int *)((int)pvVar10 + 0x138) == 0) {
        *(float *)(*(int *)((int)pvVar10 + 4) + 0x164) = (float)iVar6;
        peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        goto LAB_0011163b;
      }
      teamfrags[*(int *)((int)pvVar10 + 0x138)] = teamfrags[*(int *)((int)pvVar10 + 0x138)] + 1;
      *(float *)(*(int *)((int)pvVar10 + 4) + 0x164) = (float)iVar6;
    }
    peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar6 = peVar7->weapons;
  }
  if (iVar6 < 0) {
    iVar6 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar6 == 0) {
      in_EAX->m_rgSuitPlayList[0] = 0;
      in_EAX->m_rgSuitPlayList[1] = 0;
      in_EAX->m_rgSuitPlayList[2] = 0;
      in_EAX->m_rgSuitPlayList[3] = 0;
    }
    peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgCurWeapon,(float *)0x0,peVar7->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnWriteByte)(0xff);
  (*g_engfuncs.pfnMessageEnd)();
  in_EAX->m_iClientFOV = 0;
  in_EAX->m_iFOV = 0;
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fov = 0.0;
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgSetFOV,(float *)0x0,
             ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)(0);
  (*g_engfuncs.pfnMessageEnd)();
  in_EAX->m_iHideHUD = 9;
  peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  in_EAX->m_afPhysicsFlags = in_EAX->m_afPhysicsFlags | 0x20;
  peVar7->effects = 0x80;
  peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar7->view_ofs).x = g_vecZero.x;
  (peVar7->view_ofs).y = g_vecZero.y;
  (peVar7->view_ofs).z = g_vecZero.z;
  peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar7->v_angle).x = *in_ECX;
  (peVar7->v_angle).y = in_ECX[1];
  (peVar7->v_angle).z = in_ECX[2];
  peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar7->angles).x = (peVar7->v_angle).x;
  (peVar7->angles).y = (peVar7->v_angle).y;
  (peVar7->angles).z = (peVar7->v_angle).z;
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fixangle = 1;
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  in_EAX->m_afPhysicsFlags = in_EAX->m_afPhysicsFlags & 0xfffffff7;
  piVar1 = &peVar7->flags;
  *piVar1 = *piVar1 & 0xffffbfff;
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->deadflag = 3;
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 1.0;
  iVar6 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  iVar3 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.real_frags;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 0.0;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.respawn_time = 0.0;
  in_EAX->m_fInitHUD = 1;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.real_frags = 0;
  if (iVar6 != 0) {
    teamfrags[iVar6] = teamfrags[iVar6] - iVar3;
  }
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frags = 0.0;
  peVar7 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this_01 = (CBasePlayer *)
            (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = 0;
  peVar7->team = 0;
  (*g_engfuncs.pfnMessageBegin)(2,gmsgTeamInfo,(float *)0x0,(edict_t *)0x0);
  p_Var4 = g_engfuncs.pfnWriteByte;
  iVar6 = (*g_engfuncs.pfnIndexOfEdict)
                    (((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(iVar6);
  (*g_engfuncs.pfnWriteString)("");
  (*g_engfuncs.pfnMessageEnd)();
  removeSuit = 0;
  TeamFortress_TeamIncreaseScore((int)this_01,0);
  ((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->playerclass = 0;
  piVar1 = &(in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffbf7;
  RemoveAllItems(this_01,removeSuit);
  CleanupOnPlayerDisconnection(in_EAX);
  UTIL_SetOrigin((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,in_EDX);
  in_EAX->m_flNextObserverInput = 0.0;
  Observer_SetMode(in_EAX,in_EAX->m_iObserverLastMode);
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 0;
  TeamFortress_SetSpeed(in_EAX);
  (*g_engfuncs.pfnMessageBegin)(2,gmsgSpectator,(float *)0x0,(edict_t *)0x0);
  p_Var4 = g_engfuncs.pfnWriteByte;
  iVar6 = (*g_engfuncs.pfnIndexOfEdict)
                    (((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(iVar6);
  (*g_engfuncs.pfnWriteByte)(1);
                    /* WARNING: Could not recover jumptable at 0x00111940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::StartObserver  @ 00111010  (line 1972)

/* DWARF original prototype: void StartObserver(CBasePlayer * this, Vector vecPosition, Vector
   vecViewAngle) */

void __thiscall CBasePlayer::StartObserver(CBasePlayer *this,Vector vecPosition,Vector vecViewAngle)

{
  EHANDLE *this_00;
  int *piVar1;
  CBasePlayerItem *pCVar2;
  int iVar3;
  _func_void_int *p_Var4;
  uint uVar5;
  int iVar6;
  entvars_t *peVar7;
  CBaseEntity *pCVar8;
  edict_t *peVar9;
  void *pvVar10;
  CBasePlayer *this_01;
  BOOL removeSuit;
  
                    /* Unresolved local var: int iOldTeam@[???] */
  (*g_engfuncs.pfnMessageBegin)
            (5,0x17,&(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x7d);
  p_Var4 = g_engfuncs.pfnWriteByte;
  uVar5 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(uVar5 & 0xff);
  (*g_engfuncs.pfnMessageEnd)();
  pCVar2 = this->m_pActiveItem;
  if (pCVar2 != (CBasePlayerItem *)0x0) {
    (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar2,0);
  }
  this_00 = &this->m_pTank;
  iVar6 = EHANDLE::operator_int(this_00);
  if (iVar6 != 0) {
    pCVar8 = EHANDLE::operator->(this_00);
    (*pCVar8->_vptr_CBaseEntity[0x2d])(pCVar8,this,this,0,0);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  if (this->m_iBeingTeleported != 0) {
    PlayerStoppedTeleporting(this);
  }
  TeleporterResetEffects(this);
  iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = 0;
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invisible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invincible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.super_damage_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.radsuit_finished = 0.0;
  if (((iVar6 & 0x10) == 0) || (peVar7->enemy != peVar7->pContainingEntity)) {
LAB_00111111:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
    iVar6 = peVar7->weapons;
  }
  else {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pCVar8 = CBaseEntity::FindTimer((CBaseEntity *)this,2);
    if (pCVar8 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
      peVar9 = pCVar8->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar9 == (edict_t *)0x0) &&
         (peVar9 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar9 == (edict_t *)0x0)) {
        pvVar10 = (void *)0x0;
      }
      else {
        pvVar10 = peVar9->pvPrivateData;
      }
      iVar6 = *(int *)((int)pvVar10 + 0x144) + 1;
      *(int *)((int)pvVar10 + 0x144) = iVar6;
      if (*(int *)((int)pvVar10 + 0x138) == 0) {
        *(float *)(*(int *)((int)pvVar10 + 4) + 0x164) = (float)iVar6;
        peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        goto LAB_00111111;
      }
      teamfrags[*(int *)((int)pvVar10 + 0x138)] = teamfrags[*(int *)((int)pvVar10 + 0x138)] + 1;
      *(float *)(*(int *)((int)pvVar10 + 4) + 0x164) = (float)iVar6;
    }
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    iVar6 = peVar7->weapons;
  }
  if (iVar6 < 0) {
    iVar6 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (iVar6 == 0) {
      this->m_rgSuitPlayList[0] = 0;
      this->m_rgSuitPlayList[1] = 0;
      this->m_rgSuitPlayList[2] = 0;
      this->m_rgSuitPlayList[3] = 0;
    }
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgCurWeapon,(float *)0x0,peVar7->pContainingEntity);
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
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_afPhysicsFlags = this->m_afPhysicsFlags | 0x20;
  peVar7->effects = 0x80;
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar7->view_ofs).x = g_vecZero.x;
  (peVar7->view_ofs).y = g_vecZero.y;
  (peVar7->view_ofs).z = g_vecZero.z;
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar7->v_angle).x = *(vec_t *)vecPosition.y;
  (peVar7->v_angle).y = *(vec_t *)((int)vecPosition.y + 4);
  (peVar7->v_angle).z = *(vec_t *)((int)vecPosition.y + 8);
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar7->angles).x = (peVar7->v_angle).x;
  (peVar7->angles).y = (peVar7->v_angle).y;
  (peVar7->angles).z = (peVar7->v_angle).z;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->fixangle = 1;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 0;
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_afPhysicsFlags = this->m_afPhysicsFlags & 0xfffffff7;
  piVar1 = &peVar7->flags;
  *piVar1 = *piVar1 & 0xffffbfff;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->deadflag = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 1.0;
  iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.real_frags;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.respawn_time = 0.0;
  this->m_fInitHUD = 1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.real_frags = 0;
  if (iVar6 != 0) {
    teamfrags[iVar6] = teamfrags[iVar6] - iVar3;
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->frags = 0.0;
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this_01 = (CBasePlayer *)
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = 0;
  peVar7->team = 0;
  (*g_engfuncs.pfnMessageBegin)(2,gmsgTeamInfo,(float *)0x0,(edict_t *)0x0);
  p_Var4 = g_engfuncs.pfnWriteByte;
  iVar6 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(iVar6);
  (*g_engfuncs.pfnWriteString)("");
  (*g_engfuncs.pfnMessageEnd)();
  removeSuit = 0;
  TeamFortress_TeamIncreaseScore((int)this_01,0);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->playerclass = 0;
  piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
  *piVar1 = *piVar1 & 0xfffffbf7;
  RemoveAllItems(this_01,removeSuit);
  CleanupOnPlayerDisconnection(this);
  UTIL_SetOrigin((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev,(Vector *)vecPosition.x);
  this->m_flNextObserverInput = 0.0;
  Observer_SetMode(this,this->m_iObserverLastMode);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 0;
  TeamFortress_SetSpeed(this);
  (*g_engfuncs.pfnMessageBegin)(2,gmsgSpectator,(float *)0x0,(edict_t *)0x0);
  p_Var4 = g_engfuncs.pfnWriteByte;
  iVar6 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var4)(iVar6);
  (*g_engfuncs.pfnWriteByte)(1);
                    /* WARNING: Could not recover jumptable at 0x00111416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::CleanupOnPlayerDisconnection  @ 00110b80  (line 2093)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CleanupOnPlayerDisconnection(CBasePlayer * this) */

void __thiscall CBasePlayer::CleanupOnPlayerDisconnection(CBasePlayer *this)

{
  int *piVar1;
  uint uVar2;
  globalvars_t *pgVar3;
  CBaseEntity *pCVar4;
  CBaseEntity *pEntity;
  entvars_t *peVar5;
  int iVar6;
  CBasePlayer *pCVar7;
  edict_t *peVar8;
  CBasePlayer *pCVar9;
  float local_20;
  
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
  for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_napalmgrenade");
      pCVar4 != (CBaseEntity *)0x0;
      pCVar4 = UTIL_FindEntityByClassname(pCVar4,"tf_weapon_napalmgrenade")) {
    if (pCVar4->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar4->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_nailgrenade");
      pCVar4 != (CBaseEntity *)0x0;
      pCVar4 = UTIL_FindEntityByClassname(pCVar4,"tf_weapon_nailgrenade")) {
    if (pCVar4->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar4->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_gasgrenade");
      pCVar4 != (CBaseEntity *)0x0;
      pCVar4 = UTIL_FindEntityByClassname(pCVar4,"tf_weapon_gasgrenade")) {
    if (pCVar4->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar4->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_weapon_caltrop");
      pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"tf_weapon_caltrop"))
  {
    if (pCVar4->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar4->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_rpg_rocket");
      pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"tf_rpg_rocket")) {
    if (pCVar4->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar4->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  for (pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_ic_rocket");
      pCVar4 != (CBaseEntity *)0x0; pCVar4 = UTIL_FindEntityByClassname(pCVar4,"tf_ic_rocket")) {
    if (pCVar4->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar4->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
  TeamFortress_RemoveDetpacks(this);
  this->no_sentry_message = 1;
  this->no_dispenser_message = 1;
  this->no_entry_teleporter_message = 1;
  this->no_exit_teleporter_message = 1;
  Engineer_RemoveBuildings(this);
  pCVar4 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"detpack");
  do {
    if (pCVar4 == (CBaseEntity *)0x0) {
      pCVar9 = (CBasePlayer *)0x0;
      while (((pCVar9 = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)pCVar9,"player"),
              pCVar9 != (CBasePlayer *)0x0 &&
              (peVar8 = ((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,
              peVar8 != (edict_t *)0x0)) &&
             (iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar8), iVar6 != 0))) {
        peVar5 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        if ((peVar5 != (entvars_t *)0x0) && (pCVar9 != this)) {
          if ((peVar5->playerclass == 8) &&
             (pCVar7 = (CBasePlayer *)
                       EHANDLE::operator_CBaseEntity_
                                 (&(pCVar9->super_CBaseMonster).super_CBaseToggle.
                                   super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                   undercover_target), pCVar7 == this)) {
            TeamFortress_SpyCalcName(pCVar9);
          }
          pCVar7 = (CBasePlayer *)EHANDLE::operator_CBaseEntity_(&pCVar9->m_hObserverTarget);
          if (pCVar7 == this) {
                    /* Unresolved local var: int iMode@[???] */
            peVar5 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev;
            iVar6 = peVar5->iuser1;
            peVar5->iuser1 = 0;
            EHANDLE::operator=(&pCVar9->m_hObserverTarget,(CBaseEntity *)0x0);
            Observer_SetMode(pCVar9,iVar6);
          }
        }
      }
      return;
    }
    local_20 = pCVar4->weaponmode;
    peVar5 = pCVar4->pev;
    peVar8 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    if ((local_20 == 1.0) && (peVar5->enemy == peVar8)) {
      pCVar4->weaponmode = 0.0;
      peVar8 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity;
      local_20 = 0.0;
    }
    if (peVar5->owner == peVar8) {
      if ((local_20 == 1.0) && (peVar5->enemy != (edict_t *)0x0)) {
        iVar6 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar5->enemy);
        peVar5 = pCVar4->pev;
        if (iVar6 != 0) {
                    /* Unresolved local var: CBasePlayer * pEnemy@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
          peVar8 = peVar5->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          if (peVar8 == (edict_t *)0x0) {
            pCVar9 = (CBasePlayer *)0x0;
            peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
            if (peVar8 != (edict_t *)0x0) goto LAB_00110ea3;
          }
          else {
LAB_00110ea3:
            pCVar9 = peVar8->pvPrivateData;
          }
          piVar1 = &(pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.tfstate;
          *piVar1 = *piVar1 & 0xfffeffff;
          TeamFortress_SetSpeed(pCVar9);
          pEntity = CBaseEntity::FindTimer((CBaseEntity *)pCVar9,10);
          UTIL_Remove(pEntity);
          peVar5 = pCVar4->pev;
        }
      }
      pgVar3 = gpGlobals;
      (pCVar4->m_pfnThink).__pfn = CBaseEntity::SUB_Remove;
      (pCVar4->m_pfnThink).__delta = 0;
      peVar5->nextthink = pgVar3->time;
    }
    pCVar4 = UTIL_FindEntityByClassname(pCVar4,"detpack");
  } while( true );
}


// CBasePlayer::PlayerUse  @ 00103d10  (line 2173)

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
  int iVar8;
  uint uVar9;
  _func_int_varargs **pp_Var10;
  CBaseEntity *pCVar11;
  edict_t *peVar12;
  entvars_t *peVar13;
  int iVar14;
  CBaseEntity *pStartEntity;
  char *sample;
  float fVar15;
  undefined4 uVar16;
  float local_54;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBaseEntity * pObject@[???]
                       Unresolved local var: CBaseEntity * pClosest@[???]
                       Unresolved local var: Vector vecLOS@[???]
                       Unresolved local var: float flMaxDot@[???]
                       Unresolved local var: float flDot@[DW_OP_reg11(ST0)] */
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
    iVar8 = EHANDLE::operator_int(this_00);
    if (iVar8 != 0) {
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
                    /* Unresolved local var: CBaseEntity * pTrain@[DW_OP_reg3(EBX)] */
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    peVar12 = peVar13->groundentity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar12 == (edict_t *)0x0) {
      peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      if (peVar12 == (edict_t *)0x0) goto LAB_00103dc0;
    }
    piVar6 = peVar12->pvPrivateData;
    if (((piVar6 != (int *)0x0) && ((peVar13->button & 2) == 0)) && ((peVar13->flags & 0x200) != 0))
    {
      uVar9 = (**(code **)(*piVar6 + 0x1c))(piVar6);
      if (((uVar9 & 0x40) != 0) &&
         (iVar8 = (**(code **)(*piVar6 + 0x80))
                            (piVar6,(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev),
         iVar8 != 0)) {
        this->m_afPhysicsFlags = this->m_afPhysicsFlags | 2;
        iVar14 = (int)*(float *)(piVar6[1] + 0x1f8);
                    /* Unresolved local var: float fSpeed@[???]
                       Unresolved local var: float fMax@[???]
                       Unresolved local var: int iRet@[???] */
        iVar8 = 0xc5;
        if ((-1 < iVar14) && (iVar8 = 0xc1, iVar14 != 0)) {
          iVar8 = 0xc2;
          dVar7 = (double)iVar14 / (double)*(int *)(piVar6[1] + 0x184);
          if (0.33 <= dVar7) {
            iVar8 = (0.66 <= dVar7) + 0xc3;
          }
        }
        this->m_iTrain = iVar8;
        fVar15 = 0.8;
        sample = "plats/train_use1.wav";
        goto LAB_00103fd1;
      }
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
    }
  }
LAB_00103dc0:
  pStartEntity = (CBaseEntity *)0x0;
  UTIL_MakeVectors(&peVar13->v_angle);
  local_54 = 0.7;
  pCVar11 = (CBaseEntity *)0x0;
  while (pStartEntity = UTIL_FindEntityInSphere
                                  (pStartEntity,
                                   &((this->super_CBaseMonster).super_CBaseToggle.
                                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                    origin,64.0), pStartEntity != (CBaseEntity *)0x0) {
    uVar9 = (*pStartEntity->_vptr_CBaseEntity[7])(pStartEntity);
    if ((uVar9 & 0x38) != 0) {
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      fVar15 = (peVar13->origin).z;
      fVar1 = (peVar13->view_ofs).z;
      fVar2 = (peVar13->origin).y;
      fVar3 = (peVar13->view_ofs).y;
      fVar4 = (peVar13->origin).x;
      fVar5 = (peVar13->view_ofs).x;
      VecBModelOrigin(&local_40,pStartEntity->pev);
      local_4c.z = local_40.z - (fVar15 + fVar1);
      local_4c.y = local_40.y - (fVar2 + fVar3);
      local_4c.x = local_40.x - (fVar4 + fVar5);
      peVar13 = pStartEntity->pev;
      local_34.z = (peVar13->size).z * 0.5;
      local_34.y = (peVar13->size).y * 0.5;
      local_34.x = (peVar13->size).x * 0.5;
      UTIL_ClampVectorToBox(local_28,&local_4c,&local_34);
      local_4c.x = local_28[0].x;
      local_4c.y = local_28[0].y;
      local_4c.z = local_28[0].z;
      fVar15 = local_28[0].z * (gpGlobals->v_forward).z +
               local_28[0].y * (gpGlobals->v_forward).y + local_28[0].x * (gpGlobals->v_forward).x;
      if (local_54 < fVar15) {
        pCVar11 = pStartEntity;
        local_54 = fVar15;
      }
    }
  }
  if (pCVar11 == (CBaseEntity *)0x0) {
    if ((this->m_afButtonPressed & 0x20) == 0) {
      return;
    }
    fVar15 = 0.4;
    sample = "common/wpn_denyselect.wav";
LAB_00103fd1:
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,sample,fVar15,0.8,0
                   ,100);
    return;
  }
                    /* Unresolved local var: int caps@[???] */
  uVar9 = (*pCVar11->_vptr_CBaseEntity[7])(pCVar11);
  if ((this->m_afButtonPressed & 0x20) != 0) {
    EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "common/wpn_select.wav",0.4,0.8,0,100);
  }
  if (((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->button & 0x20) == 0) || ((uVar9 & 0x10) == 0)) {
    if (((this->m_afButtonPressed & 0x20) == 0) || ((uVar9 & 0x28) == 0)) {
      if ((this->m_afButtonReleased & 0x20) == 0) {
        return;
      }
      uVar9 = (*pCVar11->_vptr_CBaseEntity[7])(pCVar11);
      if ((uVar9 & 0x20) == 0) {
        return;
      }
      pp_Var10 = pCVar11->_vptr_CBaseEntity;
      uVar16 = 0;
      goto LAB_00103f72;
    }
    if ((uVar9 & 0x10) != 0) goto LAB_00103f61;
  }
  else {
LAB_00103f61:
    this->m_afPhysicsFlags = this->m_afPhysicsFlags | 0x10;
  }
  pp_Var10 = pCVar11->_vptr_CBaseEntity;
  uVar16 = 0x3f800000;
LAB_00103f72:
  (*pp_Var10[0x2d])(pCVar11,this,this,2,uVar16);
  return;
}


// CBasePlayer::Jump  @ 00103150  (line 2283)

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
                    /* Unresolved local var: Vector vecWallCheckDir@[???]
                       Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: entvars_t * pevGround@[???]
                       Unresolved local var: Vector vecAdjustedVelocity@[???]
                       Unresolved local var: Vector vecSpot@[???] */
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
      fVar1 = fVar2 * fVar2 + fVar4 * fVar4 + fVar1 * fVar1;
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


// FixPlayerCrouchStuck  @ 001041c0  (line 2398)

void FixPlayerCrouchStuck(edict_t *pPlayer)

{
  Vector *vecStart;
  int iVar1;
  TraceResult local_54;
  
  vecStart = &(pPlayer->v).origin;
  iVar1 = 0x12;
  do {
                    /* Unresolved local var: TraceResult trace@[???]
                       Unresolved local var: int i@[???] */
    UTIL_TraceHull(vecStart,vecStart,dont_ignore_monsters,3,pPlayer,&local_54);
    if (local_54.fStartSolid == 0) {
      return;
    }
    iVar1 = iVar1 + -1;
    (pPlayer->v).origin.z = (pPlayer->v).origin.z + 1.0;
  } while (iVar1 != 0);
  return;
}


// CBasePlayer::Duck  @ 00103120  (line 2416)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Duck(CBasePlayer * this) */

void __thiscall CBasePlayer::Duck(CBasePlayer *this)

{
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->button & 4) != 0) {
    SetAnimation(this,PLAYER_WALK);
  }
  return;
}


// CBasePlayer::Classify  @ 001001e0  (line 2429)

/* DWARF original prototype: int Classify(CBasePlayer * this) */

int __thiscall CBasePlayer::Classify(CBasePlayer *this)

{
  return 2;
}


// CBasePlayer::PlayStepSound  @ 00104230  (line 2458)

/* DWARF original prototype: void PlayStepSound(CBasePlayer * this, int step, float fvol) */

void __thiscall CBasePlayer::PlayStepSound(CBasePlayer *this,int step,float fvol)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  bool bVar4;
  char *sample;
  
                    /* Unresolved local var: int irand@[???] */
  iVar2 = (*g_pGameRules->_vptr_CGameRules[0x34])(g_pGameRules,this,fvol);
  if (iVar2 == 0) {
    return;
  }
  iVar3 = (*g_engfuncs.pfnRandomLong)(0,1);
  iVar2 = iVar3 + this->m_iStepLeft * 2;
  this->m_iStepLeft = (uint)(this->m_iStepLeft == 0);
  switch(step) {
  default:
    if (iVar2 == 1) {
      sample = "player/pl_step3.wav";
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return;
      }
      sample = "player/pl_step1.wav";
    }
    else if (iVar2 == 2) {
      sample = "player/pl_step2.wav";
    }
    else {
      if (iVar2 != 3) {
        return;
      }
      sample = "player/pl_step4.wav";
    }
    break;
  case 1:
    if (iVar2 == 1) {
      sample = "player/pl_metal3.wav";
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return;
      }
      sample = "player/pl_metal1.wav";
    }
    else if (iVar2 == 2) {
      sample = "player/pl_metal2.wav";
    }
    else {
      if (iVar2 != 3) {
        return;
      }
      sample = "player/pl_metal4.wav";
    }
    break;
  case 2:
    if (iVar2 == 1) {
      sample = "player/pl_dirt3.wav";
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return;
      }
      sample = "player/pl_dirt1.wav";
    }
    else if (iVar2 == 2) {
      sample = "player/pl_dirt2.wav";
    }
    else {
      if (iVar2 != 3) {
        return;
      }
      sample = "player/pl_dirt4.wav";
    }
    break;
  case 3:
    if (iVar2 == 1) {
      sample = "player/pl_duct3.wav";
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return;
      }
      sample = "player/pl_duct1.wav";
    }
    else if (iVar2 == 2) {
      sample = "player/pl_duct2.wav";
    }
    else {
      if (iVar2 != 3) {
        return;
      }
      sample = "player/pl_duct4.wav";
    }
    break;
  case 4:
    if (iVar2 == 1) {
      sample = "player/pl_grate3.wav";
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return;
      }
      sample = "player/pl_grate1.wav";
    }
    else if (iVar2 == 2) {
      sample = "player/pl_grate2.wav";
    }
    else {
      if (iVar2 != 3) {
        return;
      }
      sample = "player/pl_grate4.wav";
    }
    break;
  case 5:
    iVar3 = (*g_engfuncs.pfnRandomLong)(0,4);
    if (iVar3 == 0) {
switchD_001045d9_caseD_4:
      sample = "player/pl_tile5.wav";
    }
    else {
      switch(iVar2) {
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
        goto switchD_001045d9_caseD_4;
      default:
        goto switchD_001045d9_default;
      }
    }
    break;
  case 6:
    if (iVar2 == 1) {
      sample = "player/pl_slosh3.wav";
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return;
      }
      sample = "player/pl_slosh1.wav";
    }
    else if (iVar2 == 2) {
      sample = "player/pl_slosh2.wav";
    }
    else {
      if (iVar2 != 3) {
        return;
      }
      sample = "player/pl_slosh4.wav";
    }
    break;
  case 7:
    if (PlayStepSound::lexical_block_0::iSkipStep == 0) {
      PlayStepSound::lexical_block_0::iSkipStep = 1;
      return;
    }
    bVar4 = PlayStepSound::lexical_block_0::iSkipStep != 3;
    iVar1 = PlayStepSound::lexical_block_0::iSkipStep + 1;
    PlayStepSound::lexical_block_0::iSkipStep = 0;
    if (bVar4) {
      PlayStepSound::lexical_block_0::iSkipStep = iVar1;
    }
    if (iVar2 == 1) {
      sample = "player/pl_wade2.wav";
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return;
      }
      sample = "player/pl_wade1.wav";
    }
    else if (iVar2 == 2) {
      sample = "player/pl_wade3.wav";
    }
    else {
      if (iVar2 != 3) {
        return;
      }
      sample = "player/pl_wade4.wav";
    }
    break;
  case 8:
    if (iVar2 == 1) {
      sample = "player/pl_ladder3.wav";
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return;
      }
      sample = "player/pl_ladder1.wav";
    }
    else if (iVar2 == 2) {
      sample = "player/pl_ladder2.wav";
    }
    else {
      if (iVar2 != 3) {
        return;
      }
      sample = "player/pl_ladder4.wav";
    }
  }
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,4,sample,fvol,0.8,0,100);
switchD_001045d9_default:
  return;
}


// MapTextureTypeStepType  @ 00104ae0  (line 2592)

int MapTextureTypeStepType(char chTextureType)

{
  int iVar1;
  
  iVar1 = 0;
  if ((byte)(chTextureType + 0xbcU) < 0x13) {
    iVar1 = *(int *)(CSWTCH_573 + (uint)(byte)(chTextureType + 0xbcU) * 4);
  }
  return iVar1;
}


// CBasePlayer::TeleporterEffectThink  @ 00104b00  (line 2607)

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


// CBasePlayer::UpdateStepSound  @ 001032a0  (line 2626)

/* WARNING: Switch with 1 destination removed at 0x001036bb : 19 cases all go to same destination */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UpdateStepSound(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateStepSound(CBasePlayer *this)

{
  char *__s2;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  CBasePlayer *in_EAX;
  entvars_t *peVar6;
  int iVar7;
  char *__s1;
  bool bVar8;
  float fVar9;
  char local_8c [12];
  undefined1 local_80;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: char[64] szbuffer@[???]
                       Unresolved local var: char * pTextureName@[???]
                       Unresolved local var: Vector start@[???]
                       Unresolved local var: float[3] rgfl1@[???]
                       Unresolved local var: float[3] rgfl2@[???]
                       Unresolved local var: Vector knee@[???]
                       Unresolved local var: Vector feet@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[DW_OP_reg6(ESI)]
                       Unresolved local var: Vector end@[???]
                       Unresolved local var: Vector center@[???]
                       Unresolved local var: int step@[???] */
  peVar6 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (peVar6->velocity).x;
  fVar9 = (peVar6->velocity).y;
  fVar2 = (peVar6->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar9 * fVar9 + fVar1 * fVar1;
  fVar9 = SQRT(fVar1);
  if (NAN(fVar9)) {
    fVar9 = sqrtf(fVar1);
    peVar6 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  bVar8 = peVar6->movetype != 5;
  if ((peVar6->flags & 0x4000U) == 0 && bVar8) {
    fVar2 = 0.0;
    fVar4 = 210.0;
    fVar1 = 120.0;
LAB_001034e6:
    if ((peVar6->flags & 0x200U) == 0) {
      return;
    }
    fVar3 = (peVar6->velocity).x;
  }
  else {
    fVar2 = 0.1;
    fVar4 = 80.0;
    fVar1 = 60.0;
    if (bVar8) goto LAB_001034e6;
    fVar3 = (peVar6->velocity).x;
    fVar1 = 60.0;
    fVar4 = 80.0;
    fVar2 = 0.1;
    if (NAN(fVar3) || NAN(g_vecZero.x)) {
      fVar1 = 60.0;
      goto LAB_00103370;
    }
  }
  if (((fVar3 == g_vecZero.x) && ((peVar6->velocity).y == g_vecZero.y)) &&
     ((peVar6->velocity).z == g_vecZero.z)) {
    return;
  }
LAB_00103370:
  if ((fVar1 <= fVar9) || (in_EAX->m_flTimeStepSound == 0.0)) {
    SetAnimation(in_EAX,PLAYER_WALK);
    peVar6 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_28[0].z = (peVar6->absmin).z;
    fVar1 = ((peVar6->absmin).y + (peVar6->absmax).y) * 0.5;
    fVar3 = ((peVar6->absmin).x + (peVar6->absmax).x) * 0.5;
    local_34.z = ((peVar6->absmax).z - local_28[0].z) * 0.2 + local_28[0].z;
    if (bVar8) {
      local_34.x = fVar3;
      local_34.y = fVar1;
      local_28[0].x = fVar3;
      local_28[0].y = fVar1;
      iVar7 = UTIL_PointContents(&local_34);
      if (iVar7 == -3) {
        fVar1 = gpGlobals->time + 0.6;
      }
      else {
        iVar7 = UTIL_PointContents(local_28);
        if (iVar7 != -3) {
          peVar6 = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          local_38 = (peVar6->absmin).z;
          local_44 = local_38 + 4.0;
          local_38 = local_38 - 24.0;
          local_4c = fVar3;
          local_48 = fVar1;
          local_40 = fVar3;
          local_3c = fVar1;
          __s1 = (*g_engfuncs.pfnTraceTexture)(peVar6->groundentity,&local_4c,&local_40);
          if (__s1 != (char *)0x0) {
            cVar5 = *__s1;
            if (cVar5 == '-') {
              cVar5 = __s1[2];
              __s1 = __s1 + 2;
            }
            if ((cVar5 == '!') || (cVar5 == '{')) {
              __s1 = __s1 + 1;
            }
            __s2 = in_EAX->m_szTextureName;
            iVar7 = strncasecmp(__s1,__s2,0xc);
            if (iVar7 != 0) {
              strcpy(local_8c,__s1);
              local_80 = 0;
              strcpy(__s2,local_8c);
              cVar5 = TEXTURETYPE_Find(__s2);
              in_EAX->m_chTextureType = cVar5;
            }
          }
        }
        if (fVar9 < fVar4) {
          fVar1 = gpGlobals->time + 0.4;
        }
        else {
          fVar1 = gpGlobals->time + 0.3;
        }
      }
    }
    else {
      fVar1 = gpGlobals->time + 0.35;
    }
    in_EAX->m_flTimeStepSound = fVar1 + fVar2;
  }
  return;
}


// CBasePlayer::UpdateStepSound  @ 00104b50  (line 2627)

/* DWARF original prototype: void UpdateStepSound(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateStepSound(CBasePlayer *this)

{
  int iVar1;
  
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
  iVar1 = (*g_pGameRules->_vptr_CGameRules[0x34])(g_pGameRules,this,0x3f800000);
  if (((iVar1 != 0) && (this->m_flTimeStepSound < gpGlobals->time)) &&
     ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->flags & 0x1000) == 0)) {
    UpdateStepSound(this);
    return;
  }
  return;
}


// CBasePlayer::PreThink  @ 0010f320  (line 2812)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PreThink(CBasePlayer * this) */

void __thiscall CBasePlayer::PreThink(CBasePlayer *this)

{
  float fVar1;
  CBasePlayerItem *pCVar2;
  double dVar3;
  int iVar4;
  entvars_t *peVar5;
  edict_t *peVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  CBasePlayer *this_00;
  undefined4 uVar11;
  TraceResult local_5c;
  Vector local_18;
  
                    /* Unresolved local var: int buttonsChanged@[???] */
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.current_menu;
  uVar7 = peVar5->button;
  uVar8 = this->m_afButtonLast ^ uVar7;
  uVar7 = uVar7 & uVar8;
  this->m_afButtonPressed = uVar7;
  this->m_afButtonReleased = ~peVar5->button & uVar8;
  if ((fVar1 == 2.0) && ((uVar7 & 2) != 0)) {
    ResetMenu(this);
    TeamFortress_TeamPutPlayerInTeam(this);
    this->m_afButtonPressed = this->m_afButtonPressed & 0xfffffffd;
  }
  (*g_pGameRules->_vptr_CGameRules[0x13])(g_pGameRules,this);
  if (g_fGameOver != 0) {
    return;
  }
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (((peVar5->flags & 0x200) != 0) &&
     (((this->m_afPhysicsFlags & 0x10) != 0 || ((this->m_afButtonPressed & 0x20) != 0)))) {
    (peVar5->velocity).x = (peVar5->velocity).x * 0.3;
    (peVar5->velocity).y = (peVar5->velocity).y * 0.3;
    (peVar5->velocity).z = (peVar5->velocity).z * 0.3;
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
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar5->iuser1 != 0) {
    Observer_HandleButtons(this);
    Observer_CheckTarget(this);
    Observer_CheckProperties(this);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->impulse = 0;
    return;
  }
  if ((1 < peVar5->waterlevel) &&
     (0.0 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.numflames)) {
    EMIT_SOUND_DYN(peVar5->pContainingEntity,3,"ambience/steamburst1.wav",1.0,0.8,0,100);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.numflames = 0.0;
  }
  if ((this->m_flTeleporterEffectEndTime != 0.0) &&
     (this->m_flTeleporterEffectEndTime <= gpGlobals->time)) {
    TeleporterResetGlowshell(this);
  }
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (0 < peVar5->deadflag) {
    PlayerDeathThink(this);
    return;
  }
  if ((this->m_afPhysicsFlags & 2) == 0) {
    peVar5->flags = peVar5->flags & 0xfeffffff;
  }
  else {
    peVar5->flags = peVar5->flags | 0x1000000;
  }
  if ((this->m_afPhysicsFlags & 2) == 0) {
    if ((this->m_iTrain & 0x80) != 0) {
      this->m_iTrain = 0xc0;
    }
  }
  else {
                    /* Unresolved local var: CBaseEntity * pTrain@[???]
                       Unresolved local var: float vel@[???] */
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar6 = peVar5->groundentity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (peVar6 == (edict_t *)0x0) {
      peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar6 != (edict_t *)0x0) goto LAB_0010f4ba;
LAB_0010f817:
                    /* Unresolved local var: TraceResult trainTrace@[???] */
      local_18.z = (peVar5->origin).z + -38.0;
      local_18.y = (peVar5->origin).y + 0.0;
      local_18.x = (peVar5->origin).x + 0.0;
      UTIL_TraceLine(&peVar5->origin,&local_18,ignore_monsters,peVar5->pContainingEntity,&local_5c);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((((local_5c.flFraction == 1.0) || (local_5c.pHit == (edict_t *)0x0)) ||
          (piVar10 = (local_5c.pHit)->pvPrivateData, piVar10 == (int *)0x0)) ||
         ((uVar7 = (**(code **)(*piVar10 + 0x1c))(piVar10), (uVar7 & 0x40) == 0 ||
          (iVar4 = (**(code **)(*piVar10 + 0x80))
                             (piVar10,(this->super_CBaseMonster).super_CBaseToggle.
                                      super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev),
          iVar4 == 0)))) {
LAB_0010f790:
        this->m_afPhysicsFlags = this->m_afPhysicsFlags & 0xfffffffd;
        this->m_iTrain = 0xc0;
        return;
      }
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    else {
LAB_0010f4ba:
      piVar10 = peVar6->pvPrivateData;
      if (piVar10 == (int *)0x0) goto LAB_0010f817;
      if ((((peVar5->flags & 0x200) == 0) || ((*(byte *)(piVar10[1] + 0x1a0) & 2) != 0)) ||
         ((peVar5->button & 0x600U) != 0)) goto LAB_0010f790;
    }
    (peVar5->velocity).x = g_vecZero.x;
    (peVar5->velocity).y = g_vecZero.y;
    (peVar5->velocity).z = g_vecZero.z;
    if ((this->m_afButtonPressed & 8U) == 0) {
      if ((this->m_afButtonPressed & 0x10U) == 0) goto LAB_0010f5ec;
      iVar4 = *piVar10;
      uVar11 = 0xbf800000;
    }
    else {
      iVar4 = *piVar10;
      uVar11 = 0x3f800000;
    }
    (**(code **)(iVar4 + 0xb4))(piVar10,this,this,2,uVar11);
                    /* Unresolved local var: float fSpeed@[???]
                       Unresolved local var: float fMax@[???]
                       Unresolved local var: int iRet@[???] */
    iVar9 = 0xc5;
    iVar4 = (int)*(float *)(piVar10[1] + 0x1f8);
    if ((-1 < iVar4) && (iVar9 = 0xc1, iVar4 != 0)) {
      iVar9 = 0xc2;
      dVar3 = (double)iVar4 / (double)*(int *)(piVar10[1] + 0x184);
      if (0.33 <= dVar3) {
        iVar9 = (0.66 <= dVar3) + 0xc3;
      }
    }
    this->m_iTrain = iVar9;
  }
LAB_0010f5ec:
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar7 = peVar5->button;
  if (((((uVar7 & 2) != 0) && (peVar5->movetype != 5)) && (cease_fire == 0)) &&
     ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_building == 0 &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_detpacking == 0)) &&
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.is_feigning == 0)))) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x86])(this);
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    uVar7 = peVar5->button;
  }
  if ((((uVar7 & 4) != 0) || ((peVar5->flags & 0x4000) != 0)) || ((this->m_afPhysicsFlags & 8) != 0)
     ) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x87])(this);
  }
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: char[64] szbuffer@[???]
                       Unresolved local var: char * pTextureName@[???]
                       Unresolved local var: Vector start@[???]
                       Unresolved local var: float[3] rgfl1@[???]
                       Unresolved local var: Vector end@[???]
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
  this_00 = (CBasePlayer *)g_pGameRules;
  iVar4 = (*g_pGameRules->_vptr_CGameRules[0x34])(g_pGameRules,this,0x3f800000);
  if (iVar4 != 0) {
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    uVar7 = peVar5->flags;
    if ((gpGlobals->time <= this->m_flTimeStepSound) || ((uVar7 & 0x1000) != 0)) goto LAB_0010f6b5;
    UpdateStepSound(this_00);
  }
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  uVar7 = peVar5->flags;
LAB_0010f6b5:
  if ((uVar7 & 0x200) == 0) {
    this->m_flFallVelocity = -(peVar5->velocity).z;
  }
  EHANDLE::operator=(&(this->super_CBaseMonster).m_hEnemy,(CBaseEntity *)0x0);
  if ((this->m_afPhysicsFlags & 4) != 0) {
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar5->velocity).x = g_vecZero.x;
    (peVar5->velocity).y = g_vecZero.y;
    (peVar5->velocity).z = g_vecZero.z;
  }
  return;
}


// CBasePlayer::CheckTimeBasedDamage  @ 00104bb0  (line 3188)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckTimeBasedDamage(CBasePlayer * this) */

void __thiscall CBasePlayer::CheckTimeBasedDamage(CBasePlayer *this)

{
  int *piVar1;
  entvars_t *peVar2;
  float fVar3;
  uchar uVar4;
  globalvars_t *pgVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  CBasePlayer *this_00;
  entvars_t *in_stack_ffffffb8;
  entvars_t *in_stack_ffffffbc;
  int in_stack_ffffffc0;
  
  pgVar5 = gpGlobals;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: BYTE bDuration@[???]
                       Unresolved local var: float gtbdPrev@[???] */
  fVar3 = this->m_flConcStartTime + this->m_flConcDuration;
  if (fVar3 <= gpGlobals->time) {
    this->m_iConcussion = 0;
  }
  else {
    this->m_iConcussion =
         (int)((float)this->m_iConcStartVal * ((fVar3 - gpGlobals->time) / this->m_flConcDuration));
  }
  uVar7 = (this->super_CBaseMonster).m_bitsDamageType;
  if (((uVar7 & 0xffc000) == 0) ||
     (uVar11 = (uint)(pgVar5->time - this->m_tbdPrev), uVar9 = (int)uVar11 >> 0x1f,
     (float)(int)((uVar11 ^ uVar9) - uVar9) < 2.0)) {
    return;
  }
  this->m_tbdPrev = pgVar5->time;
  iVar10 = 0;
  uVar4 = '\0';
  do {
    uVar9 = 0x8000 << ((byte)iVar10 & 0x1f);
    if ((uVar9 & uVar7) != 0) {
      if (iVar10 == 2) {
        in_stack_ffffffb8 =
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
        in_stack_ffffffc0 = 0x40000000;
        in_stack_ffffffbc = in_stack_ffffffb8;
        (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0xd])(this);
        uVar4 = '\x05';
      }
      else if (iVar10 == 4) {
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if ((1.0 <= peVar2->health) && (peVar2->deadflag == 0)) {
          uVar4 = '\x04';
          if (this->m_idrownrestored < this->m_idrowndmg) {
                    /* Unresolved local var: int idif@[???] */
            iVar8 = this->m_idrowndmg - this->m_idrownrestored;
            if (10 < iVar8) {
              iVar8 = 10;
            }
            in_stack_ffffffb8 = (entvars_t *)(float)iVar8;
            in_stack_ffffffbc = (entvars_t *)0x0;
            (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity[0xe])(this);
            this->m_idrownrestored = this->m_idrownrestored + iVar8;
          }
        }
      }
      else {
        uVar4 = '\x02';
      }
      bVar6 = (this->super_CBaseMonster).m_rgbTimeBasedDamage[iVar10];
      if (bVar6 == 0) {
        (this->super_CBaseMonster).m_rgbTimeBasedDamage[iVar10] = uVar4;
      }
      else {
        if (iVar10 == 1) {
          if (bVar6 < 2) goto LAB_00104db0;
LAB_00104c8d:
          (this->super_CBaseMonster).m_rgbTimeBasedDamage[iVar10] = bVar6 - 1;
          if ((byte)(bVar6 - 1) != '\0') goto LAB_00104ca0;
        }
        else {
          if ((iVar10 != 2) || (4 < bVar6)) goto LAB_00104c8d;
LAB_00104db0:
          iVar8 = this->m_rgItems[2];
          if (iVar8 == 0) goto LAB_00104c8d;
          (this->super_CBaseMonster).m_rgbTimeBasedDamage[iVar10] = '\0';
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
          peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev;
          this->m_rgItems[2] = iVar8 + -1;
          if ((peVar2->weapons < 0) &&
             (this_00 = (CBasePlayer *)g_pGameRules, iVar8 = (*g_pGameRules->_vptr_CGameRules[6])(),
             iVar8 == 0)) {
            SetSuitUpdate(this_00,(char *)in_stack_ffffffb8,(int)in_stack_ffffffbc,in_stack_ffffffc0
                         );
          }
          bVar6 = (this->super_CBaseMonster).m_rgbTimeBasedDamage[iVar10];
          if (bVar6 != 0) goto LAB_00104c8d;
        }
        (this->super_CBaseMonster).m_rgbTimeBasedDamage[iVar10] = '\0';
        piVar1 = &(this->super_CBaseMonster).m_bitsDamageType;
        *piVar1 = *piVar1 & ~uVar9;
      }
    }
LAB_00104ca0:
    iVar10 = iVar10 + 1;
    if (iVar10 == 8) {
      return;
    }
    uVar7 = (this->super_CBaseMonster).m_bitsDamageType;
  } while( true );
}


// CBasePlayer::UpdateGeigerCounter  @ 00104e50  (line 3372)

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
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,3);
    if (iVar2 == 0) {
      this->m_flgeigerRange = 1000.0;
    }
  }
  return;
}


// CBasePlayer::CheckSuitUpdate  @ 00104f20  (line 3412)

/* DWARF original prototype: void CheckSuitUpdate(CBasePlayer * this) */

void __thiscall CBasePlayer::CheckSuitUpdate(CBasePlayer *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_1d [21];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int isearch@[???] */
  iVar3 = this->m_iSuitPlayNext;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->weapons < 0) {
    UpdateGeigerCounter(this);
    iVar1 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
    if (((iVar1 == 0) && (this->m_flSuitUpdate <= gpGlobals->time)) && (0.0 < this->m_flSuitUpdate))
    {
      iVar1 = iVar3 + 0x1d4;
      iVar2 = this->m_rgSuitPlayList[iVar3];
      if (iVar2 == 0) {
        iVar3 = iVar3 + 1;
        if (iVar3 == 4) {
          iVar3 = 0;
        }
        iVar1 = iVar3 + 0x1d4;
        iVar2 = this->m_rgSuitPlayList[iVar3];
        if (iVar2 == 0) {
          iVar3 = iVar3 + 1;
          if (iVar3 == 4) {
            iVar3 = 0;
          }
          iVar1 = iVar3 + 0x1d4;
          iVar2 = this->m_rgSuitPlayList[iVar3];
          if (iVar2 == 0) {
            iVar3 = iVar3 + 1;
            if (iVar3 == 4) {
              iVar3 = 0;
            }
            iVar1 = iVar3 + 0x1d4;
            iVar2 = this->m_rgSuitPlayList[iVar3];
            if (iVar2 == 0) {
              this->m_flSuitUpdate = 0.0;
              return;
            }
          }
        }
      }
      (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)[iVar1] = (entvars_t *)0x0;
      if (iVar2 < 1) {
        EMIT_GROUPID_SUIT(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,-iVar2);
      }
      else {
                    /* Unresolved local var: char[17] sentence@[???] */
        local_1d[0] = '!';
        local_1d[1] = '\0';
        strcat(local_1d,gszallsentencenames[iVar2]);
        EMIT_SOUND_SUIT(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,local_1d);
      }
      this->m_flSuitUpdate = gpGlobals->time + 3.5;
    }
  }
  return;
}


// CBasePlayer::SetSuitUpdate  @ 00100ae0  (line 3473)

/* DWARF original prototype: void SetSuitUpdate(CBasePlayer * this, char * name, int fgroup, int
   iNoRepeatTime) */

void __thiscall
CBasePlayer::SetSuitUpdate(CBasePlayer *this,char *name,int fgroup,int iNoRepeatTime)

{
  float fVar1;
  globalvars_t *pgVar2;
  int in_EAX;
  int iVar3;
  char *in_EDX;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int isentence@[???]
                       Unresolved local var: int iempty@[???] */
  iVar3 = SENTENCEG_Lookup(in_EDX,(char *)0x0);
  pgVar2 = gpGlobals;
  if (-1 < iVar3) {
    iVar4 = 0;
    do {
      if (iVar3 == *(int *)(in_EAX + 0x768 + iVar4 * 4)) {
        if (gpGlobals->time <= *(float *)(in_EAX + 8 + (iVar4 + 0x1f8) * 4)) {
          return;
        }
        *(undefined4 *)(in_EAX + 0x768 + iVar4 * 4) = 0;
        *(undefined4 *)(in_EAX + 8 + (iVar4 + 0x1f8) * 4) = 0;
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x20);
    iVar4 = *(int *)(in_EAX + 0x764);
    *(int *)(in_EAX + 0x754 + iVar4 * 4) = iVar3;
    iVar4 = iVar4 + 1;
    iVar3 = 0;
    if (iVar4 != 4) {
      iVar3 = iVar4;
    }
    *(int *)(in_EAX + 0x764) = iVar3;
    fVar1 = pgVar2->time;
    if (*(float *)(in_EAX + 0x750) <= fVar1) {
      if (*(float *)(in_EAX + 0x750) == 0.0) {
        *(float *)(in_EAX + 0x750) = fVar1 + 0.1;
        return;
      }
      *(float *)(in_EAX + 0x750) = fVar1 + 3.5;
    }
  }
  return;
}


// CBasePlayer::SetSuitUpdate  @ 00105080  (line 3474)

/* DWARF original prototype: void SetSuitUpdate(CBasePlayer * this, char * name, int fgroup, int
   iNoRepeatTime) */

void __thiscall
CBasePlayer::SetSuitUpdate(CBasePlayer *this,char *name,int fgroup,int iNoRepeatTime)

{
  float fVar1;
  int iVar2;
  int iVar3;
  globalvars_t *pgVar4;
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
      iVar3 = -1;
      iVar5 = 0;
      do {
        if (this->m_rgiSuitNoRepeat[iVar5] == iVar2) {
          if (gpGlobals->time <= this->m_rgflSuitNoRepeatTime[iVar5]) {
            return;
          }
          this->m_rgiSuitNoRepeat[iVar5] = 0;
          this->m_rgflSuitNoRepeatTime[iVar5] = 0.0;
          iVar3 = iVar5;
          break;
        }
        if (this->m_rgiSuitNoRepeat[iVar5] == 0) {
          iVar3 = iVar5;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      pgVar4 = gpGlobals;
      if (iNoRepeatTime != 0) {
        if (iVar3 == -1) {
          iVar3 = (*g_engfuncs.pfnRandomLong)(0,0x1f);
        }
        this->m_rgiSuitNoRepeat[iVar3] = iVar2;
        pgVar4 = gpGlobals;
        this->m_rgflSuitNoRepeatTime[iVar3] = (float)iNoRepeatTime + gpGlobals->time;
      }
      iVar3 = this->m_iSuitPlayNext;
      this->m_rgSuitPlayList[iVar3] = iVar2;
      iVar3 = iVar3 + 1;
      iVar2 = 0;
      if (iVar3 != 4) {
        iVar2 = iVar3;
      }
      this->m_iSuitPlayNext = iVar2;
      fVar1 = pgVar4->time;
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


// CBasePlayer::CheckPowerups  @ 00105240  (line 3576)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckPowerups(CBasePlayer * this) */

void __thiscall CBasePlayer::CheckPowerups(CBasePlayer *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  entvars_t *peVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  globalvars_t *pgVar9;
  vec_t vVar10;
  longdouble lVar11;
  
                    /* Unresolved local var: BOOL bIsInvisible@[???]
                       Unresolved local var: BOOL bIsInvincible@[???]
                       Unresolved local var: BOOL bIsQuadded@[???] */
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar4->health <= 0.0) {
    return;
  }
  peVar4->modelindex = g_ulModelIndexPlayer;
  pgVar9 = gpGlobals;
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.invisible_finished;
  if (fVar2 == 0.0) {
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.invincible_finished;
    uVar5 = false;
    if (NAN(fVar2)) goto LAB_0010540e;
LAB_001052e7:
    if (fVar2 != 0.0) goto LAB_0010540e;
    uVar6 = false;
    uVar8 = false;
LAB_001052f3:
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.super_damage_finished;
    if (NAN(fVar2)) goto LAB_001054d0;
LAB_00105307:
    if (fVar2 != 0.0) goto LAB_001054d0;
    uVar7 = false;
  }
  else {
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x40) != 0) {
      fVar2 = gpGlobals->time + 10.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.invisible_finished = fVar2;
    }
    fVar3 = pgVar9->time;
    if ((fVar2 < fVar3 + 3.0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostInvisSound == 0)) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Item_ringfade",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,"items/inv2.wav",
                     1.0,0.8,0,100);
      pgVar9 = gpGlobals;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_bLostInvisSound = 1;
      fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.invisible_finished;
      fVar3 = pgVar9->time;
    }
    if (fVar2 < fVar3) {
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_bLostInvisSound = 0;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.items;
      *piVar1 = *piVar1 & 0xfff7ffff;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.invisible_finished = 0.0;
      peVar4->rendermode = 0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderfx = 0;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
    }
    uVar5 = fVar2 >= fVar3;
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.invincible_finished;
    if (!NAN(fVar2)) goto LAB_001052e7;
LAB_0010540e:
    pgVar9 = gpGlobals;
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x20) != 0) {
      fVar2 = gpGlobals->time + 10.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.invincible_finished = fVar2;
    }
    fVar3 = pgVar9->time;
    if ((fVar2 < fVar3 + 3.0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostInvincSound == 0)) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Item_pentfade",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                     "items/protect2.wav",1.0,0.8,0,100);
      pgVar9 = gpGlobals;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_bLostInvincSound = 1;
      fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.invincible_finished;
      fVar3 = pgVar9->time;
    }
    if (fVar3 <= fVar2) {
      uVar6 = true;
      uVar8 = true;
      goto LAB_001052f3;
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_bLostInvincSound = 0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    uVar6 = false;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 & 0xffefffff;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.invincible_finished = 0.0;
    peVar4->renderfx = 0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar4->rendercolor).x = g_vecZero.x;
    (peVar4->rendercolor).y = g_vecZero.y;
    (peVar4->rendercolor).z = g_vecZero.z;
    uVar8 = false;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 0.0;
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.super_damage_finished;
    if (!NAN(fVar2)) goto LAB_00105307;
    uVar6 = false;
LAB_001054d0:
    pgVar9 = gpGlobals;
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x80) != 0) {
      fVar2 = gpGlobals->time + 10.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.super_damage_finished = fVar2;
    }
    fVar3 = pgVar9->time;
    if ((fVar2 < fVar3 + 3.0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostSuperSound == 0)) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Item_quadfade",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                     "items/damage3.wav",1.0,0.8,0,100);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_bLostSuperSound = 1;
      fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.super_damage_finished;
      fVar3 = gpGlobals->time;
    }
    if (fVar2 < fVar3) {
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.items;
      *piVar1 = *piVar1 & 0xffbfffff;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_bLostSuperSound = 0;
      vVar10 = g_vecZero.x;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.super_damage_finished = 0.0;
      peVar4->renderfx = 0;
      uVar7 = false;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar4->rendercolor).x = vVar10;
      (peVar4->rendercolor).y = g_vecZero.y;
      (peVar4->rendercolor).z = g_vecZero.z;
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->renderamt = 0.0;
      fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.radsuit_finished;
      pgVar9 = gpGlobals;
      goto code_r0x0010557f;
    }
    uVar6 = true;
    uVar7 = true;
  }
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.radsuit_finished;
  pgVar9 = gpGlobals;
code_r0x0010557f:
  gpGlobals = pgVar9;
  if (fVar2 != 0.0) {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->air_finished = pgVar9->time + 12.0;
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x100) == 0) {
      fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.radsuit_finished;
    }
    else {
      fVar2 = pgVar9->time + 10.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.radsuit_finished = fVar2;
    }
    fVar3 = pgVar9->time;
    if ((fVar2 < fVar3 + 3.0) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.m_bLostRadSound == 0)) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Item_suitfade",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
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
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.items;
      *piVar1 = *piVar1 & 0xffdfffff;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.radsuit_finished = 0.0;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_bLostRadSound = 0;
    }
  }
  if (((bool)uVar6) &&
     (peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev, peVar4->renderfx == 0)) {
    peVar4->renderfx = 0x13;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->renderamt = 100.0;
    if (((bool)uVar7) && ((bool)uVar8)) {
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar4->rendercolor).x = 255.0;
      (peVar4->rendercolor).y = 128.0;
      (peVar4->rendercolor).z = 255.0;
    }
    else if ((bool)uVar8) {
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar4->rendercolor).x = 255.0;
      (peVar4->rendercolor).y = 128.0;
      (peVar4->rendercolor).z = 0.0;
    }
    else if ((bool)uVar7) {
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      (peVar4->rendercolor).x = 128.0;
      (peVar4->rendercolor).y = 128.0;
      (peVar4->rendercolor).z = 255.0;
    }
  }
  if ((bool)uVar5) {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->rendermode = 5;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    lVar11 = (longdouble)(*g_engfuncs.pfnRandomFloat)(1.0,255.0);
    peVar4->renderamt = (float)(int)lVar11;
  }
  return;
}


// CBasePlayer::UpdatePlayerSound  @ 00105970  (line 3737)

/* DWARF original prototype: void UpdatePlayerSound(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdatePlayerSound(CBasePlayer *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  globalvars_t *pgVar4;
  int iVar5;
  CSound *pCVar6;
  entvars_t *peVar7;
  int iVar8;
  int iVar9;
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
    iVar5 = 0;
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar7->flags & 0x200) != 0) {
      fVar1 = (peVar7->velocity).x;
      fVar10 = (peVar7->velocity).y;
      fVar2 = (peVar7->velocity).z;
      fVar1 = fVar2 * fVar2 + fVar10 * fVar10 + fVar1 * fVar1;
      fVar10 = SQRT(fVar1);
      if (NAN(fVar10)) {
        fVar10 = sqrtf(fVar1);
        peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      iVar5 = (int)fVar10;
      if (0x200 < iVar5) {
        iVar5 = 0x200;
      }
    }
    if ((peVar7->button & 2) != 0) {
      iVar5 = iVar5 + 100;
    }
    iVar8 = this->m_iWeaponVolume;
    if (iVar5 < iVar8) {
      this->m_iTargetVolume = iVar8;
      pCVar6->m_iType = pCVar6->m_iType | 1;
      iVar8 = this->m_iWeaponVolume;
      iVar5 = this->m_iTargetVolume;
      peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    else {
      this->m_iTargetVolume = iVar5;
    }
    pgVar4 = gpGlobals;
    this->m_iWeaponVolume = (int)((float)iVar8 - gpGlobals->frametime * 250.0);
    iVar8 = pCVar6->m_iVolume;
    iVar9 = iVar5;
    if (((iVar5 <= iVar8) && (iVar9 = iVar8, iVar5 < iVar8)) &&
       (iVar9 = (int)((float)iVar8 - pgVar4->frametime * 250.0), iVar9 < iVar5)) {
      iVar9 = 0;
    }
    if (this->m_fNoPlayerSound != 0) {
      iVar9 = 0;
    }
    if (this->m_flStopExtraSoundTime < pgVar4->time) {
      this->m_iExtraSoundTypes = 0;
    }
    (pCVar6->m_vecOrigin).x = (peVar7->origin).x;
    (pCVar6->m_vecOrigin).y = (peVar7->origin).y;
    (pCVar6->m_vecOrigin).z = (peVar7->origin).z;
    uVar3 = this->m_iExtraSoundTypes;
    pCVar6->m_iVolume = iVar9;
    pCVar6->m_iType = pCVar6->m_iType | uVar3 | 4;
    iVar8 = (int)((float)this->m_iWeaponFlash - gpGlobals->frametime * 256.0);
    iVar5 = 0;
    if (-1 < iVar8) {
      iVar5 = iVar8;
    }
    this->m_iWeaponFlash = iVar5;
  }
  return;
}


// CBasePlayer::PostThink  @ 00105b70  (line 3853)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PostThink(CBasePlayer * this) */

void __thiscall CBasePlayer::PostThink(CBasePlayer *this)

{
  EHANDLE *this_00;
  float fVar1;
  CBasePlayerItem *pCVar2;
  _func_int_varargs *p_Var3;
  float fVar4;
  globalvars_t *pgVar5;
  int iVar6;
  CBaseEntity *pCVar7;
  edict_t *peVar8;
  entvars_t *peVar9;
  entvars_t *peVar10;
  int iVar11;
  CBasePlayer *this_01;
  
  if (g_fGameOver != 0) goto LAB_00105b89;
  Player_Menu(this);
  iVar11 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
  if ((iVar11 == 0) ||
     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->deadflag == 5)) goto LAB_00105b89;
  this_00 = &this->m_pTank;
  iVar11 = EHANDLE::operator_int(this_00);
  if (iVar11 != 0) {
    pCVar7 = EHANDLE::operator->(this_00);
    iVar11 = (*pCVar7->_vptr_CBaseEntity[0x20])
                       (pCVar7,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev);
    if ((iVar11 == 0) ||
       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->weaponmodel != 0)) {
      pCVar7 = EHANDLE::operator->(this_00);
      (*pCVar7->_vptr_CBaseEntity[0x2d])(pCVar7,this,this,0,0);
      EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
    }
    else {
      pCVar7 = EHANDLE::operator->(this_00);
      (*pCVar7->_vptr_CBaseEntity[0x2d])(pCVar7,this,this,2,0x40000000);
    }
  }
                    /* Unresolved local var: int fInSelect@[???] */
  if (((((cease_fire == 0) &&
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.is_building == 0)) &&
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_detpacking == 0)) &&
      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_feigning == 0 && (iVar11 = EHANDLE::operator_int(this_00), iVar11 == 0)
       ))) && ((this->super_CBaseMonster).m_flNextAttack <= 0.0)) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8a])(this);
    pCVar2 = this->m_pActiveItem;
    if (pCVar2 != (CBasePlayerItem *)0x0) {
      (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4c])
                (pCVar2);
    }
  }
  peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if ((peVar10->flags & 0x200) != 0) {
    fVar1 = this->m_flFallVelocity;
    if ((0.0 < peVar10->health) && (350.0 <= fVar1)) {
      if (peVar10->watertype == -3) {
LAB_00105e47:
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: char[64] szbuffer@[???]
                       Unresolved local var: char * pTextureName@[???]
                       Unresolved local var: Vector start@[???]
                       Unresolved local var: float[3] rgfl1@[???]
                       Unresolved local var: Vector end@[???]
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
        this_01 = (CBasePlayer *)g_pGameRules;
        this->m_flTimeStepSound = 0.0;
        iVar11 = (*((CGameRules *)this_01)->_vptr_CGameRules[0x34])(this_01,this,0x3f800000);
        if ((iVar11 != 0) &&
           ((this->m_flTimeStepSound < gpGlobals->time &&
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->flags & 0x1000) == 0)))) {
          UpdateStepSound(this_01);
        }
      }
      else {
        if (650.0 < fVar1) {
          fVar1 = (fVar1 / 300.0) * 5.0;
          if (peVar10->playerclass == 1) {
            fVar1 = fVar1 * 0.5;
          }
          else if (peVar10->playerclass == 6) {
            fVar1 = fVar1 * 1.5;
          }
          if (peVar10->health < fVar1) {
            EMIT_SOUND_DYN(peVar10->pContainingEntity,3,"common/bodysplat.wav",1.0,0.8,0,100);
          }
          if (0.0 < fVar1) {
            p_Var3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0xd];
            peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
            peVar10 = &peVar8->v;
            if (peVar8 == (edict_t *)0x0) {
              peVar10 = (entvars_t *)0x0;
            }
            peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
            peVar9 = (entvars_t *)0x0;
            if (peVar8 != (edict_t *)0x0) {
              peVar9 = &peVar8->v;
            }
            (*p_Var3)(this,peVar9,peVar10,fVar1,0x8000020);
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->punchangle).x = 0.0;
          }
          goto LAB_00105e47;
        }
        if ((325.0 < fVar1) || (200.0 <= fVar1)) goto LAB_00105e47;
      }
      iVar11 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
      if (iVar11 != 0) {
        SetAnimation(this,PLAYER_WALK);
      }
      if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->flags & 0x200) == 0) goto LAB_00105eef;
      fVar1 = this->m_flFallVelocity;
    }
    if ((64.0 < fVar1) && (iVar11 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules), iVar11 == 0)
       ) {
      CSoundEnt::InsertSound
                (4,&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->origin,(int)this->m_flFallVelocity,0.2
                );
    }
    this->m_flFallVelocity = 0.0;
  }
LAB_00105eef:
  iVar11 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
  if (iVar11 != 0) {
    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (((peVar10->velocity).x == 0.0) && ((peVar10->velocity).y == 0.0)) {
      SetAnimation(this,PLAYER_IDLE);
    }
    else if (((peVar10->flags & 0x200) != 0) || (1 < peVar10->waterlevel)) {
      SetAnimation(this,PLAYER_WALK);
    }
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  CheckPowerups(this);
  UpdatePlayerSound(this);
LAB_00105b89:
                    /* Unresolved local var: float fvol@[???]
                       Unresolved local var: float flFallDamage@[???] */
  iVar11 = 0;
  do {
                    /* Unresolved local var: int i@[???] */
    for (pCVar2 = this->m_rgpPlayerItems[iVar11]; pCVar2 != (CBasePlayerItem *)0x0;
        pCVar2 = pCVar2->m_pNext) {
                    /* Unresolved local var: CBasePlayerItem * pPlayerItem@[???]
                       Unresolved local var: CBasePlayerWeapon * gun@[???] */
      iVar6 = (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                [0x53])(pCVar2);
      pgVar5 = gpGlobals;
      if (iVar6 != 0) {
        fVar1 = *(float *)(iVar6 + 0x4a4) - gpGlobals->frametime;
        if (fVar1 <= -1.0) {
          fVar1 = -1.0;
        }
        *(float *)(iVar6 + 0x4a4) = fVar1;
        fVar1 = *(float *)(iVar6 + 0x4c0) - pgVar5->frametime;
        if (fVar1 <= -1.0) {
          fVar1 = -1.0;
        }
        *(float *)(iVar6 + 0x4c0) = fVar1;
        fVar1 = *(float *)(iVar6 + 0x4a8) - pgVar5->frametime;
        fVar4 = -0.001;
        if (-0.001 < fVar1) {
          fVar4 = fVar1;
        }
        *(float *)(iVar6 + 0x4a8) = fVar4;
        fVar1 = *(float *)(iVar6 + 0x4b0) - pgVar5->frametime;
        fVar4 = -0.001;
        if (-0.001 < fVar1) {
          fVar4 = fVar1;
        }
        *(float *)(iVar6 + 0x4b0) = fVar4;
        if (*(float *)(iVar6 + 0x4b4) != 1000.0) {
          fVar1 = *(float *)(iVar6 + 0x4b4) - pgVar5->frametime;
          fVar4 = -0.001;
          if (-0.001 < fVar1) {
            fVar4 = fVar1;
          }
          *(float *)(iVar6 + 0x4b4) = fVar4;
        }
        if (*(float *)(iVar6 + 0x4ac) != 1000.0) {
          fVar1 = *(float *)(iVar6 + 0x4ac) - pgVar5->frametime;
          fVar4 = -0.001;
          if (-0.001 < fVar1) {
            fVar4 = fVar1;
          }
          *(float *)(iVar6 + 0x4ac) = fVar4;
        }
      }
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 != 6);
  fVar1 = (this->super_CBaseMonster).m_flNextAttack - gpGlobals->frametime;
  (this->super_CBaseMonster).m_flNextAttack = fVar1;
  if (fVar1 < -0.001) {
    (this->super_CBaseMonster).m_flNextAttack = -0.001;
  }
  this->m_afButtonLast =
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->button;
  return;
}


// IsSpawnPointValid  @ 00106150  (line 4026)

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


// EntSelectSpawnPoint  @ 001061a0  (line 4052)

edict_t * EntSelectSpawnPoint(edict_t *player)

{
  _func_int_varargs *p_Var1;
  CBaseEntity *pCVar2;
  int iVar3;
  edict_t *peVar4;
  CBaseEntity *pCVar5;
  int32 iVar6;
  CBaseEntity *pStartEntity;
  entvars_t *peVar7;
  entvars_t *peVar8;
  
                    /* Unresolved local var: CBaseEntity * pSpot@[???]
                       Unresolved local var: CBaseEntity * pPlayer@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar4 = player;
  if ((player == (edict_t *)0x0) &&
     (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
    pCVar5 = (CBaseEntity *)0x0;
  }
  else {
    pCVar5 = peVar4->pvPrivateData;
  }
  if ((((pCVar5->team_no != 0) &&
       (pCVar5 = CBaseEntity::FindTeamSpawnPoint(pCVar5), pCVar5 != (CBaseEntity *)0x0)) &&
      (peVar4 = pCVar5->pev->pContainingEntity, peVar4 != (edict_t *)0x0)) &&
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar3 != 0)) {
    return pCVar5->pev->pContainingEntity;
  }
  pCVar5 = g_pLastSpawn;
  if (gpGlobals->coop == 0.0) {
    if (gpGlobals->deathmatch == 0.0) {
LAB_001061f6:
      if ((gpGlobals->startspot != 0) && (gpGlobals->pStringBase[gpGlobals->startspot] != '\0')) {
        pCVar5 = UTIL_FindEntityByTargetname
                           ((CBaseEntity *)0x0,gpGlobals->pStringBase + gpGlobals->startspot);
        if ((pCVar5 == (CBaseEntity *)0x0) ||
           (peVar4 = pCVar5->pev->pContainingEntity, peVar4 == (edict_t *)0x0)) goto LAB_00106250;
        (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4);
        goto LAB_0010639d;
      }
      pCVar2 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"info_player_start");
      if ((pCVar2 == (CBaseEntity *)0x0) ||
         (peVar4 = pCVar2->pev->pContainingEntity, peVar4 == (edict_t *)0x0)) goto LAB_00106250;
      (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4);
      peVar4 = pCVar2->pev->pContainingEntity;
    }
    else {
                    /* Unresolved local var: int i@[???] */
      iVar6 = (*g_engfuncs.pfnRandomLong)(1,5);
      if (0 < iVar6) {
        do {
          pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_player_deathmatch");
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      if (((pCVar5 == (CBaseEntity *)0x0) ||
          (peVar4 = pCVar5->pev->pContainingEntity, peVar4 == (edict_t *)0x0)) ||
         (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), pCVar2 = pCVar5, iVar3 == 0)) {
        pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_player_deathmatch");
        pCVar2 = pCVar5;
      }
      do {
        if (((pCVar5 != (CBaseEntity *)0x0) &&
            (peVar4 = pCVar5->pev->pContainingEntity, peVar4 != (edict_t *)0x0)) &&
           (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar3 != 0)) {
          peVar8 = pCVar5->pev;
          pStartEntity = (CBaseEntity *)0x0;
          do {
            pStartEntity = UTIL_FindEntityInSphere(pStartEntity,&peVar8->origin,96.0);
            if (pStartEntity == (CBaseEntity *)0x0) {
              peVar8 = pCVar5->pev;
              if ((((peVar8->origin).x != 0.0) || ((peVar8->origin).y != 0.0)) ||
                 ((peVar8->origin).z != 0.0)) goto LAB_001063c0;
              break;
            }
                    /* Unresolved local var: CBaseEntity * ent@[???] */
          } while ((pStartEntity->pev->flags & 8) == 0);
        }
        pCVar5 = UTIL_FindEntityByClassname(pCVar5,"info_player_deathmatch");
      } while (pCVar2 != pCVar5);
      if ((pCVar2 == (CBaseEntity *)0x0) ||
         (peVar4 = pCVar2->pev->pContainingEntity, peVar4 == (edict_t *)0x0)) goto LAB_001061f6;
      pCVar5 = (CBaseEntity *)0x0;
      iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4);
      if (iVar3 == 0) goto LAB_001061f6;
                    /* Unresolved local var: CBaseEntity * ent@[???] */
      while (pCVar5 = UTIL_FindEntityInSphere(pCVar5,&pCVar2->pev->origin,128.0),
            pCVar5 != (CBaseEntity *)0x0) {
        if (((pCVar5->pev->flags & 8) != 0) && (player != pCVar5->pev->pContainingEntity)) {
          p_Var1 = pCVar5->_vptr_CBaseEntity[0xd];
          peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(0);
          peVar8 = &peVar4->v;
          if (peVar4 == (edict_t *)0x0) {
            peVar8 = (entvars_t *)0x0;
          }
          peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(0);
          peVar7 = &peVar4->v;
          if (peVar4 == (edict_t *)0x0) {
            peVar7 = (entvars_t *)0x0;
          }
          (*p_Var1)(pCVar5,peVar7,peVar8,0x43960000,0);
        }
      }
      peVar4 = pCVar2->pev->pContainingEntity;
    }
  }
  else {
    pCVar5 = UTIL_FindEntityByClassname(g_pLastSpawn,"info_player_coop");
    if ((((pCVar5 == (CBaseEntity *)0x0) ||
         (peVar4 = pCVar5->pev->pContainingEntity, peVar4 == (edict_t *)0x0)) ||
        (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar3 == 0)) &&
       (((pCVar5 = UTIL_FindEntityByClassname(g_pLastSpawn,"info_player_start"),
         pCVar5 == (CBaseEntity *)0x0 ||
         (peVar4 = pCVar5->pev->pContainingEntity, peVar4 == (edict_t *)0x0)) ||
        (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar3 == 0)))) goto LAB_001061f6;
LAB_0010639d:
    peVar8 = pCVar5->pev;
LAB_001063c0:
    pCVar2 = pCVar5;
    peVar4 = peVar8->pContainingEntity;
  }
  if ((peVar4 != (edict_t *)0x0) &&
     (iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar4), iVar3 != 0)) {
    g_pLastSpawn = pCVar2;
    return pCVar2->pev->pContainingEntity;
  }
LAB_00106250:
  (*g_engfuncs.pfnAlertMessage)(at_error,"PutClientInServer: no info_player_start on level");
                    /* WARNING: Could not recover jumptable at 0x00106278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  peVar4 = (*g_engfuncs.pfnPEntityOfEntIndex)(0);
  return peVar4;
}


// CBasePlayer::Spawn  @ 0010d4e0  (line 4144)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CBasePlayer * this) */

void __thiscall CBasePlayer::Spawn(CBasePlayer *this)

{
  float fVar1;
  _func_int_varargs **pp_Var2;
  edict_t *peVar3;
  int pc;
  int iVar4;
  globalvars_t *pgVar5;
  BOOL BVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  entvars_t *peVar13;
  bool bVar14;
  ushort in_FPUControlWord;
  longdouble extraout_ST0;
  char local_70 [32];
  Vector local_50;
  Vector local_44;
  Vector local_38;
  Vector local_2c;
  ushort local_1e;
  
                    /* Unresolved local var: int iszoom@[???] */
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"player" - (int)gpGlobals->pStringBase;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 100.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->armorvalue = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 3;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 3;
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  peVar13->max_health = peVar13->health;
  pgVar5 = gpGlobals;
  piVar9 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar9 = *piVar9 & 0x100000;
  piVar9 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar9 = *piVar9 | 8;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->air_finished = pgVar5->time + 12.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg = 2.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->effects = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->deadflag = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg_take = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg_save = 0.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->friction = 1.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->gravity = 1.0;
  this->m_fLongJump = 0;
  this->m_iFOV = 0;
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  this->m_bitsHUDDamage = -1;
  (this->super_CBaseMonster).m_bitsDamageType = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uint team_allies_composite@[???]
                       Unresolved local var: char[32] sz@[???] */
  this->m_afPhysicsFlags = 0;
  peVar13->fov = 0.0;
  this->m_iClientFOV = -1;
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  this->m_flNextDecalTime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_flSafetyCheckTime = 0.0;
  peVar13->iuser3 = 0;
  TeleporterResetEffects(this);
  (*g_engfuncs.pfnSetPhysicsKeyValue)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"tfc","1");
  sprintf(local_70,"%u",
          (teamallies[4] & 0x1fU) << 0x14 |
          (teamallies[1] & 0x1fU) << 5 | teamallies[0] & 0x1fU | (teamallies[2] & 0x1fU) << 10 |
          (teamallies[3] & 0x1fU) << 0xf);
  (*g_engfuncs.pfnSetPhysicsKeyValue)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"ta",local_70);
  fVar1 = gpGlobals->time;
  this->m_iStepLeft = 0;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  pp_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity;
  this->m_flTimeStepSound = 0.0;
  (this->super_CBaseMonster).m_flFieldOfView = 0.5;
  (this->super_CBaseMonster).m_flNextAttack = 0.0;
  this->m_flgeigerDelay = fVar1 + 2.0;
  (*pp_Var2[0x1e])(this);
  this->m_iFlashBattery = 99;
  this->m_iBeingTeleported = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = 0;
  pgVar5 = gpGlobals;
  this->m_MenuStringBuffer[0] = '\0';
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_displaytime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.menu_refreshtime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.current_menu = 1.0;
  this->m_flFlashLightTime = 1.0;
  this->m_flFallVelocity = 0.0;
  this->m_flConcDuration = 0.0;
  this->m_flConcStartTime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.super_damage_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.radsuit_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invisible_finished = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.invincible_finished = 0.0;
  fVar1 = pgVar5->time;
  this->m_iTeamToDisguiseAs = 0;
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  this->m_flNextSBarUpdateTime = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.numflames = 0.0;
  this->m_iClientIsFeigning = -1;
  this->m_iClientIsDetpacking = -1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.immune_to_check = fVar1 + 10.0;
  this->m_iClientBuildState = -1;
  this->m_iClientRandomPC = -1;
  peVar3 = peVar13->pContainingEntity;
  (*g_engfuncs.pfnSetView)(peVar3,peVar3);
  iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.nextpc;
  if (iVar7 == 0) {
    uVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate;
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
  }
  else {
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->playerclass = iVar7;
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.nextpc = 0;
    uVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate;
    if (peVar13->playerclass == 10) {
      uVar11 = uVar11 | 8;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.tfstate = uVar11;
    }
    else {
      uVar11 = uVar11 & 0xfffffff7;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.tfstate = uVar11;
    }
  }
  if ((uVar11 & 8) != 0) {
                    /* Unresolved local var: int oldclass@[???] */
    iVar7 = peVar13->playerclass;
LAB_0010d860:
    (*g_engfuncs.pfnRandomFloat)(0.0,9.0);
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    local_1e = in_FPUControlWord & 0xf3ff | 0x400;
    peVar13->playerclass = (int)((double)ROUND(extraout_ST0) + 1.0);
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    pc = peVar13->playerclass;
                    /* Unresolved local var: int bit@[???] */
    if (pc == 8) goto LAB_0010d9a0;
    goto LAB_0010d8db;
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 0;
  iVar7 = 0x1000;
joined_r0x0010ddb7:
  if ((uVar11 & 0x1000) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = iVar7;
  }
  iVar7 = peVar13->playerclass;
  if (((iVar7 != 10) && (iVar7 != 0)) &&
     (iVar7 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.lastpc)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.lastpc = iVar7;
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.exec_scripts != 0) {
      (*g_engfuncs.pfnMessageBegin)(1,0x3b,(float *)0x0,peVar13->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(1);
      (*g_engfuncs.pfnWriteByte)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->playerclass);
      (*g_engfuncs.pfnMessageEnd)();
      peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
    }
    iVar7 = peVar13->playerclass;
  }
  if (iVar7 != 9) {
    Engineer_RemoveBuildings(this);
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
  }
  peVar13->takedamage = 2.0;
  pcVar8 = UTIL_VarArgs("#%s",sClassNames
                              [((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->playerclass]);
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,pcVar8,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  TeamFortress_SetEquipment(this);
  TeamFortress_SetHealth(this);
  TeamFortress_SetSpeed(this);
  TeamFortress_SetSkin(this);
  pgVar5 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.building_wait = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.sniper_zoom = 0.0;
  this->m_cSpamPoints = 0;
  fVar1 = pgVar5->time;
  this->m_flGagTime = -1.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = PlayerTouch;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  this->m_flLastTalkTime = fVar1;
  iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tf_id;
  if (iVar7 != 0) {
    pcVar8 = UTIL_dtos1(iVar7);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_battleid",pcVar8,(char *)0x0,(char *)0x0,(char *)0x0)
    ;
  }
  (*g_pGameRules->_vptr_CGameRules[0x16])(g_pGameRules,this);
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  iVar7 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  peVar13->sequence = iVar7;
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if ((peVar13->flags & 0x4000) == 0) {
    local_2c.x = 16.0;
    local_2c.y = 16.0;
    local_2c.z = 36.0;
    local_38.x = -16.0;
    local_38.y = -16.0;
    local_38.z = -36.0;
    UTIL_SetSize(peVar13,&local_38,&local_2c);
  }
  else {
    local_44.x = 16.0;
    local_44.y = 16.0;
    local_44.z = 18.0;
    local_50.x = -16.0;
    local_50.y = -16.0;
    local_50.z = -18.0;
    UTIL_SetSize(peVar13,&local_50,&local_44);
  }
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (peVar13->view_ofs).x = 0.0;
  (peVar13->view_ofs).y = 0.0;
  (peVar13->view_ofs).z = 28.0;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[3])(this);
  iVar7 = this->m_iPlayerSound;
  (this->super_CBaseMonster).m_HackedGunPos.x = 0.0;
  (this->super_CBaseMonster).m_HackedGunPos.y = 32.0;
  (this->super_CBaseMonster).m_HackedGunPos.z = 0.0;
  if (iVar7 == -1) {
    (*g_engfuncs.pfnAlertMessage)(at_console,"Couldn\'t alloc player sound slot!\n");
  }
  this->m_fNoPlayerSound = 0;
  uVar11 = 0x80;
  this->m_fInitHUD = 1;
  this->m_iClientHideHUD = -1;
  this->m_fWeapon = 0;
  this->m_iMaxArmor = -1;
  piVar9 = this->m_rgAmmo;
  this->m_pClientActiveItem = (CBasePlayerItem *)0x0;
  bVar14 = ((uint)piVar9 & 1) != 0;
  this->m_iClientBattery = -1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.cl_no_grenades_2 = -1.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.cl_no_grenades_1 = -1.0;
  if (bVar14) {
    piVar9 = (int *)((int)this->m_rgAmmo + 1);
    uVar11 = 0x7f;
    *(undefined1 *)this->m_rgAmmo = 0;
  }
  if (((uint)piVar9 & 2) != 0) {
    *(undefined2 *)piVar9 = 0;
    uVar11 = uVar11 - 2;
    piVar9 = (int *)((int)piVar9 + 2);
  }
  uVar10 = 0;
  do {
    *(undefined4 *)((int)piVar9 + uVar10 + 4) = 0;
    *(undefined4 *)((int)piVar9 + uVar10) = 0;
    *(undefined4 *)((int)piVar9 + uVar10 + 8) = 0;
    *(undefined4 *)((int)piVar9 + uVar10 + 0xc) = 0;
    uVar10 = uVar10 + 0x10;
  } while (uVar10 < (uVar11 & 0xfffffff0));
  puVar12 = (undefined4 *)((int)piVar9 + uVar10);
  if ((uVar11 & 8) != 0) {
    *puVar12 = 0;
    puVar12[1] = 0;
    puVar12 = puVar12 + 2;
  }
  if ((uVar11 & 4) != 0) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  if ((uVar11 & 2) != 0) {
    *(undefined2 *)puVar12 = 0;
    puVar12 = (undefined4 *)((int)puVar12 + 2);
  }
  if (bVar14) {
    *(undefined1 *)puVar12 = 0;
  }
  piVar9 = this->m_rgAmmoLast;
  uVar11 = 0x80;
  bVar14 = ((uint)piVar9 & 1) != 0;
  if (bVar14) {
    *(undefined1 *)this->m_rgAmmoLast = 0;
    piVar9 = (int *)((int)this->m_rgAmmoLast + 1);
    uVar11 = 0x7f;
  }
  if (((uint)piVar9 & 2) != 0) {
    *(undefined2 *)piVar9 = 0;
    uVar11 = uVar11 - 2;
    piVar9 = (int *)((int)piVar9 + 2);
  }
  uVar10 = 0;
  do {
    *(undefined4 *)((int)piVar9 + uVar10 + 4) = 0;
    *(undefined4 *)((int)piVar9 + uVar10) = 0;
    *(undefined4 *)((int)piVar9 + uVar10 + 8) = 0;
    *(undefined4 *)((int)piVar9 + uVar10 + 0xc) = 0;
    uVar10 = uVar10 + 0x10;
  } while (uVar10 < (uVar11 & 0xfffffff0));
  puVar12 = (undefined4 *)((int)piVar9 + uVar10);
  if ((uVar11 & 8) != 0) {
    *puVar12 = 0;
    puVar12[1] = 0;
    puVar12 = puVar12 + 2;
  }
  if ((uVar11 & 4) != 0) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  if ((uVar11 & 2) != 0) {
    *(undefined2 *)puVar12 = 0;
    puVar12 = (undefined4 *)((int)puVar12 + 2);
  }
  if (bVar14) {
    *(undefined1 *)puVar12 = 0;
  }
  this->m_lasty = 0;
  this->m_lastx = 0;
  (*g_pGameRules->_vptr_CGameRules[0x12])(g_pGameRules,this);
  return;
LAB_0010d9a0:
  if (spy_off == 1.0) goto LAB_0010d860;
LAB_0010d8db:
  uVar10 = 1;
  if ((((((pc != 1) && (uVar10 = 2, pc != 2)) && (uVar10 = 4, pc != 3)) &&
       (((uVar10 = 8, pc != 4 && (uVar10 = 0x10, pc != 5)) &&
        ((uVar10 = 0x20, pc != 6 && ((uVar10 = 0x40, pc != 7 && (uVar10 = 0x100, pc != 8)))))))) &&
      (uVar10 = 0x200, pc != 9)) && (uVar10 = 0, pc == 10)) {
    uVar10 = 0x80;
  }
  if ((((illegalclasses[0] & uVar10) != 0) ||
      (iVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no, (illegalclasses[iVar4] & uVar10) != 0)) || (iVar7 == pc))
  goto LAB_0010d860;
  BVar6 = ClassIsRestricted((float)iVar4,pc);
  if (BVar6 != 0) {
    peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    goto LAB_0010d860;
  }
  this->m_pszLastItem = (char *)0x0;
  peVar13 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 8;
  iVar7 = 0x1008;
  this->m_nFirstSpawn = 1;
  goto joined_r0x0010ddb7;
}


// CBasePlayer::Precache  @ 00113430  (line 4351)

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
  (this->super_CBaseMonster).m_bitsDamageType = 0;
  this->m_bitsHUDDamage = -1;
  this->m_iClientBattery = -1;
  this->m_iMaxArmor = -1;
  this->m_iTrain = 0xc0;
  this->m_flgeigerRange = 1000.0;
  this->m_igeigerRangePrev = 1000;
  LinkUserMessages();
  BVar1 = gInitHUD;
  this->m_iUpdateTime = 5;
  if (BVar1 != 0) {
    this->m_fInitHUD = 1;
  }
  return;
}


// CBasePlayer::Save  @ 00100a80  (line 4397)

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


// CBasePlayer::RenewItems  @ 00106840  (line 4411)

/* DWARF original prototype: void RenewItems(CBasePlayer * this) */

void __thiscall CBasePlayer::RenewItems(CBasePlayer *this)

{
  return;
}


// CBasePlayer::Restore  @ 00106630  (line 4414)

/* DWARF original prototype: int Restore(CBasePlayer * this, CRestore * restore) */

int __thiscall CBasePlayer::Restore(CBasePlayer *this,CRestore *restore)

{
  float fVar1;
  float fVar2;
  int iVar3;
  edict_t *peVar4;
  entvars_t *peVar5;
  entvars_t *peVar6;
  int iVar7;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: int status@[DW_OP_reg6(ESI)]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  iVar7 = 0;
  iVar3 = CBaseMonster::Restore(&this->super_CBaseMonster,restore);
  if (iVar3 != 0) {
                    /* Unresolved local var: int status@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
    iVar7 = CRestore::ReadFields(restore,"PLAYER",this,m_playerSaveData,0x26);
    if (*(int *)((int)gpGlobals->pSaveData + 0x52c) == 0) {
                    /* Unresolved local var: edict_t * pentSpawnSpot@[???] */
      (*g_engfuncs.pfnAlertMessage)(at_console,"No Landmark:%s\n",(int)gpGlobals->pSaveData + 0x530)
      ;
      peVar4 = EntSelectSpawnPoint(((this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   pContainingEntity);
      peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if (peVar4 == (edict_t *)0x0) {
        fVar1 = fRam00000010 + 1.0;
        fVar2 = fRam0000000c + 0.0;
        peVar5 = (entvars_t *)0x0;
        (peVar6->origin).x = fRam00000008 + 0.0;
        (peVar6->origin).y = fVar2;
        (peVar6->origin).z = fVar1;
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      else {
        fVar1 = (peVar4->v).origin.z;
        fVar2 = (peVar4->v).origin.y;
        peVar5 = &peVar4->v;
        (peVar6->origin).x = (peVar4->v).origin.x + 0.0;
        (peVar6->origin).y = fVar2 + 0.0;
        (peVar6->origin).z = fVar1 + 1.0;
        peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      (peVar6->angles).x = (peVar5->angles).x;
      (peVar6->angles).y = (peVar5->angles).y;
      (peVar6->angles).z = (peVar5->angles).z;
    }
    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev)->v_angle).z = 0.0;
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar6->angles).x = (peVar6->v_angle).x;
    (peVar6->angles).y = (peVar6->v_angle).y;
    (peVar6->angles).z = (peVar6->v_angle).z;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->fixangle = 1;
    peVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).m_bloodColor = 0xf7;
    g_ulModelIndexPlayer = peVar6->modelindex;
    if ((peVar6->flags & 0x4000) == 0) {
      local_24.x = 16.0;
      local_24.y = 16.0;
      local_24.z = 36.0;
      local_18.x = -16.0;
      local_18.y = -16.0;
      local_18.z = -36.0;
      UTIL_SetSize(peVar6,&local_18,&local_24);
    }
    else {
      local_3c.x = 16.0;
      local_3c.y = 16.0;
      local_3c.z = 18.0;
      local_30.x = -16.0;
      local_30.y = -16.0;
      local_30.z = -18.0;
      UTIL_SetSize(peVar6,&local_30,&local_3c);
    }
  }
  return iVar7;
}


// CBasePlayer::SelectNextItem  @ 00106850  (line 4460)

/* DWARF original prototype: void SelectNextItem(CBasePlayer * this, int iItem) */

void __thiscall CBasePlayer::SelectNextItem(CBasePlayer *this,int iItem)

{
  CBasePlayerItem *pCVar1;
  CBasePlayerItem *pCVar2;
  CBasePlayerItem *pCVar3;
  CBasePlayerItem *pCVar4;
  
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
  pCVar4 = this->m_rgpPlayerItems[iItem];
  if (pCVar4 != (CBasePlayerItem *)0x0) {
    pCVar1 = this->m_pActiveItem;
    if (pCVar1 == pCVar4) {
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
                    /* WARNING: Could not recover jumptable at 0x00106940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x4a])();
      return;
    }
  }
  return;
}


// CBasePlayer::SelectItem  @ 001069a0  (line 4506)

/* DWARF original prototype: void SelectItem(CBasePlayer * this, char * pstr) */

void __thiscall CBasePlayer::SelectItem(CBasePlayer *this,char *pstr)

{
  char *pcVar1;
  CBasePlayerItem *pCVar2;
  int iVar3;
  CBasePlayerItem *pCVar4;
  CBasePlayerItem *pCVar5;
  int iVar6;
  
                    /* Unresolved local var: CBasePlayerItem * pItem@[???] */
  if (pstr != (char *)0x0) {
    iVar6 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      pCVar5 = this->m_rgpPlayerItems[iVar6];
      if (pCVar5 != (CBasePlayerItem *)0x0) {
        pcVar1 = gpGlobals->pStringBase;
        do {
          iVar3 = strcmp(pcVar1 + ((pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity
                                  .pev)->classname,pstr);
          if (iVar3 == 0) {
            if (pCVar5 != (CBasePlayerItem *)0x0) {
              if (pCVar5 == this->m_pActiveItem) {
                return;
              }
              iVar6 = (*(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                        _vptr_CBaseEntity[0x46])(pCVar5);
              if (iVar6 == 0) {
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
              pCVar2 = this->m_pActiveItem;
              this->m_fOnTarget = 0;
              pCVar4 = (CBasePlayerItem *)0x0;
              if (pCVar2 != (CBasePlayerItem *)0x0) {
                (*(pCVar2->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x49])(pCVar2,0);
                pCVar4 = this->m_pActiveItem;
              }
              this->m_pLastItem = pCVar4;
              this->m_pActiveItem = pCVar5;
              (*(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                [0x47])(pCVar5);
                    /* WARNING: Could not recover jumptable at 0x00106b00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x4a])();
              return;
            }
            break;
          }
          pCVar5 = pCVar5->m_pNext;
        } while (pCVar5 != (CBasePlayerItem *)0x0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 6);
  }
  return;
}


// CBasePlayer::SelectLastItem  @ 00106b10  (line 4558)

/* DWARF original prototype: void SelectLastItem(CBasePlayer * this) */

void __thiscall CBasePlayer::SelectLastItem(CBasePlayer *this)

{
  int iVar1;
  CBasePlayerItem *pCVar2;
  CBasePlayerItem *pCVar3;
  
                    /* Unresolved local var: CBasePlayerItem * pTemp@[???] */
  if (this->m_pLastItem == (CBasePlayerItem *)0x0) {
    return;
  }
  pCVar3 = this->m_pActiveItem;
  if (pCVar3 == (CBasePlayerItem *)0x0) {
    pCVar3 = (CBasePlayerItem *)0x0;
  }
  else {
    iVar1 = (*(pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x48])(pCVar3);
    if (iVar1 == 0) {
      return;
    }
    pCVar3 = this->m_pActiveItem;
    if (this->m_pLastItem == pCVar3) {
      return;
    }
  }
  if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
    (this->m_vecAutoAim).x = 0.0;
    (this->m_vecAutoAim).y = 0.0;
    (this->m_vecAutoAim).z = 0.0;
    (*g_engfuncs.pfnCrosshairAngle)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
    pCVar3 = this->m_pActiveItem;
  }
  this->m_fOnTarget = 0;
  pCVar2 = (CBasePlayerItem *)0x0;
  if (pCVar3 != (CBasePlayerItem *)0x0) {
    (*(pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
              (pCVar3,0);
    pCVar2 = this->m_pActiveItem;
  }
  pCVar3 = this->m_pLastItem;
  this->m_pLastItem = pCVar2;
  this->m_pActiveItem = pCVar3;
  (*(pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
            (pCVar3);
                    /* WARNING: Could not recover jumptable at 0x00106c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
    [0x4a])();
  return;
}


// CBasePlayer::HasWeapons  @ 00106c50  (line 4591)

/* DWARF original prototype: BOOL HasWeapons(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::HasWeapons(CBasePlayer *this)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???] */
  uVar1 = 1;
  if ((((this->m_rgpPlayerItems[0] == (CBasePlayerItem *)0x0) &&
       (this->m_rgpPlayerItems[1] == (CBasePlayerItem *)0x0)) &&
      (this->m_rgpPlayerItems[2] == (CBasePlayerItem *)0x0)) &&
     ((this->m_rgpPlayerItems[3] == (CBasePlayerItem *)0x0 &&
      (this->m_rgpPlayerItems[4] == (CBasePlayerItem *)0x0)))) {
    uVar1 = (uint)(this->m_rgpPlayerItems[5] != (CBasePlayerItem *)0x0);
  }
  return uVar1;
}


// CBasePlayer::SelectPrevItem  @ 00106ca0  (line 4608)

/* DWARF original prototype: void SelectPrevItem(CBasePlayer * this, int iItem) */

void __thiscall CBasePlayer::SelectPrevItem(CBasePlayer *this,int iItem)

{
  return;
}


// CSprayCan::ObjectCaps  @ 001139d0  (line 4621)

/* DWARF original prototype: int ObjectCaps(CSprayCan * this) */

int __thiscall CSprayCan::ObjectCaps(CSprayCan *this)

{
  return -0x80000000;
}


// CSprayCan::Spawn  @ 00106cb0  (line 4625)

/* DWARF original prototype: void Spawn(CSprayCan * this, entvars_t * pevOwner) */

void __thiscall CSprayCan::Spawn(CSprayCan *this,entvars_t *pevOwner)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  
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
  pgVar4 = gpGlobals;
  ((this->super_CBaseEntity).pev)->frame = 0.0;
  ((this->super_CBaseEntity).pev)->nextthink = pgVar4->time + 0.1;
  EMIT_SOUND_DYN(((this->super_CBaseEntity).pev)->pContainingEntity,2,"player/sprayer.wav",1.0,0.8,0
                 ,100);
  return;
}


// CSprayCan::Think  @ 00100810  (line 4636)

/* WARNING: Variable defined which should be unmapped: playernum */
/* DWARF original prototype: void Think(CSprayCan * this) */

void __thiscall CSprayCan::Think(CSprayCan *this)

{
  float fVar1;
  edict_t *peVar2;
  entvars_t *peVar3;
  int playernum_00;
  int iVar4;
  TraceResult local_60;
  Vector local_28 [2];
  int playernum;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: int nFrames@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg2(EDX)] */
  iVar4 = -1;
  peVar2 = ((this->super_CBaseEntity).pev)->owner;
  if ((peVar2 != (edict_t *)0x0) && (peVar2->pvPrivateData != (void *)0x0)) {
    iVar4 = *(int *)((int)peVar2->pvPrivateData + 0xa5c);
  }
  playernum_00 = (*g_engfuncs.pfnIndexOfEdict)(peVar2);
  UTIL_MakeVectors(&((this->super_CBaseEntity).pev)->angles);
  peVar3 = (this->super_CBaseEntity).pev;
  local_28[0].z = (gpGlobals->v_forward).z * 128.0 + (peVar3->origin).z;
  local_28[0].y = (gpGlobals->v_forward).y * 128.0 + (peVar3->origin).y;
  local_28[0].x = (gpGlobals->v_forward).x * 128.0 + (peVar3->origin).x;
  UTIL_TraceLine(&peVar3->origin,local_28,ignore_monsters,peVar3->owner,&local_60);
  if (iVar4 == -1) {
    UTIL_DecalTrace(&local_60,10);
    UTIL_Remove(&this->super_CBaseEntity);
  }
  else {
    UTIL_PlayerDecalTrace(&local_60,playernum_00,(int)((this->super_CBaseEntity).pev)->frame,1);
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


// CBloodSplat::Spawn  @ 00106d70  (line 4681)

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


// CBloodSplat::Spray  @ 00100740  (line 4691)

/* DWARF original prototype: void Spray(CBloodSplat * this) */

void __thiscall CBloodSplat::Spray(CBloodSplat *this)

{
  int iVar1;
  globalvars_t *pgVar2;
  TraceResult local_50;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  if (g_Language != 1) {
    UTIL_MakeVectors((Vector *)(*(int *)(this + 4) + 0x50));
    iVar1 = *(int *)(this + 4);
    local_18.z = (gpGlobals->v_forward).z * 128.0 + *(float *)(iVar1 + 0x10);
    local_18.y = (gpGlobals->v_forward).y * 128.0 + *(float *)(iVar1 + 0xc);
    local_18.x = (gpGlobals->v_forward).x * 128.0 + *(float *)(iVar1 + 8);
    UTIL_TraceLine((Vector *)(iVar1 + 8),&local_18,ignore_monsters,*(edict_t **)(iVar1 + 0x198),
                   &local_50);
    UTIL_BloodDecalTrace(&local_50,0xf7);
  }
  pgVar2 = gpGlobals;
  *(code **)(this + 0x10) = CBaseEntity::SUB_Remove;
  *(undefined4 *)(this + 0x14) = 0;
  *(float *)(*(int *)(this + 4) + 0x104) = pgVar2->time + 0.1;
  return;
}


// CBasePlayer::GiveNamedItem  @ 00106df0  (line 4710)

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
                    /* WARNING: Could not recover jumptable at 0x00106e3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_console,"NULL Ent in GiveNamedItem!\n");
  return;
}


// FindEntityForward  @ 00106e90  (line 4730)

CBaseEntity * FindEntityForward(CBaseEntity *pMe)

{
  entvars_t *peVar1;
  int iVar2;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  UTIL_MakeVectors(&pMe->pev->v_angle);
  peVar1 = pMe->pev;
  local_24.z = (peVar1->origin).z + (peVar1->view_ofs).z;
  local_24.y = (peVar1->origin).y + (peVar1->view_ofs).y;
  local_24.x = (peVar1->view_ofs).x;
  local_18.z = (gpGlobals->v_forward).z * 8192.0 + local_24.z;
  local_18.y = (gpGlobals->v_forward).y * 8192.0 + local_24.y;
  local_18.x = (peVar1->origin).x + local_24.x + (gpGlobals->v_forward).x * 8192.0;
  local_24.x = local_24.x + (peVar1->origin).x;
  UTIL_TraceLine(&local_24,&local_18,dont_ignore_monsters,peVar1->pContainingEntity,&local_5c);
                    /* Unresolved local var: CBaseEntity * pHit@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((local_5c.flFraction != 1.0) && (local_5c.pHit != (edict_t *)0x0)) &&
      (iVar2 = (*g_engfuncs.pfnEntOffsetOfPEntity)(local_5c.pHit), iVar2 != 0)) &&
     ((local_5c.pHit != (edict_t *)0x0 ||
      (local_5c.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0), local_5c.pHit != (edict_t *)0x0)))) {
    return (local_5c.pHit)->pvPrivateData;
  }
  return (CBaseEntity *)0x0;
}


// CBasePlayer::FlashlightIsOn  @ 00106fa0  (line 4746)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL FlashlightIsOn(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::FlashlightIsOn(CBasePlayer *this)

{
  return ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.pev)->effects & 8;
}


// CBasePlayer::FlashlightTurnOn  @ 00106fc0  (line 4751)

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


// CBasePlayer::FlashlightTurnOff  @ 001070a0  (line 4773)

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


// CBasePlayer::ForceClientDllUpdate  @ 00109940  (line 4795)

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


// CBasePlayer::ImpulseCommands  @ 001073d0  (line 4822)

/* DWARF original prototype: void ImpulseCommands(CBasePlayer * this) */

void __thiscall CBasePlayer::ImpulseCommands(CBasePlayer *this)

{
  int *piVar1;
  int iImpulse;
  entvars_t *peVar2;
  edict_t *peVar3;
  CSprayCan *this_00;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: int iImpulse@[???] */
  PlayerUse(this);
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iImpulse = peVar2->impulse;
  if (iImpulse == 99) {
                    /* Unresolved local var: int iOn@[???] */
    if (gmsgLogo == 0) {
      gmsgLogo = (*g_engfuncs.pfnRegUserMsg)("Logo",1);
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgLogo,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(1);
      (*g_engfuncs.pfnMessageEnd)();
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    else {
      (*g_engfuncs.pfnMessageBegin)(1,gmsgLogo,(float *)0x0,peVar2->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
      gmsgLogo = 0;
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    goto LAB_00107413;
  }
  if (iImpulse < 100) {
    if (iImpulse == 0x32) {
      this->m_iHideHUD = this->m_iHideHUD | 4;
      goto LAB_00107413;
    }
LAB_00107404:
    CheatImpulseCommands(this,iImpulse);
  }
  else {
    if (iImpulse == 100) {
      if ((peVar2->effects & 8) == 0) {
        FlashlightTurnOn(this);
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      else {
        EMIT_SOUND_DYN(peVar2->pContainingEntity,1,"items/flashlight1.wav",1.0,0.8,0,100);
        piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->effects;
        *piVar1 = *piVar1 & 0xfffffff7;
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgFlashlight,(float *)0x0,
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnWriteByte)(0);
        (*g_engfuncs.pfnWriteByte)(this->m_iFlashBattery);
        (*g_engfuncs.pfnMessageEnd)();
        this->m_flFlashLightTime = gpGlobals->time + 0.2;
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      }
      goto LAB_00107413;
    }
    if (iImpulse != 0xc9) goto LAB_00107404;
    if (gpGlobals->time < this->m_flNextDecalTime) goto LAB_00107413;
    UTIL_MakeVectors(&peVar2->v_angle);
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_24.z = (peVar2->origin).z + (peVar2->view_ofs).z;
    local_24.y = (peVar2->origin).y + (peVar2->view_ofs).y;
    local_24.x = (peVar2->view_ofs).x;
    local_18.z = (gpGlobals->v_forward).z * 128.0 + local_24.z;
    local_18.y = (gpGlobals->v_forward).y * 128.0 + local_24.y;
    local_18.x = (peVar2->origin).x + local_24.x + (gpGlobals->v_forward).x * 128.0;
    local_24.x = local_24.x + (peVar2->origin).x;
    UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar2->pContainingEntity,&local_5c);
    if (local_5c.flFraction != 1.0) {
                    /* Unresolved local var: CSprayCan * pCan@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
      this->m_flNextDecalTime = gpGlobals->time + decalfrequency.value;
      peVar3 = (*g_engfuncs.pfnCreateEntity)();
      peVar2 = (entvars_t *)0x0;
      if (peVar3 != (edict_t *)0x0) {
        peVar2 = &peVar3->v;
      }
      if ((peVar2->pContainingEntity == (edict_t *)0x0) ||
         (this_00 = peVar2->pContainingEntity->pvPrivateData, this_00 == (CSprayCan *)0x0)) {
        this_00 = CBaseEntity::operator_new(0x474,peVar2);
        (this_00->super_CBaseEntity)._vptr_CBaseEntity =
             (_func_int_varargs **)&PTR__CSprayCan_001894e8;
        (this_00->super_CBaseEntity).pev = peVar2;
      }
      CSprayCan::Spawn(this_00,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev);
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      goto LAB_00107413;
    }
  }
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
LAB_00107413:
  peVar2->impulse = 0;
  return;
}


// CBasePlayer::CheatImpulseCommands  @ 00107160  (line 4903)

/* DWARF original prototype: void CheatImpulseCommands(CBasePlayer * this, int iImpulse) */

void __thiscall CBasePlayer::CheatImpulseCommands(CBasePlayer *this,int iImpulse)

{
  entvars_t *peVar1;
  _func_void_ALERT_TYPE_char_ptr_varargs *p_Var2;
  int iVar3;
  edict_t *peVar4;
  char *pcVar5;
  longdouble extraout_ST0;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  (*g_engfuncs.pfnCVarGetFloat)("sv_cheats");
  p_Var2 = g_engfuncs.pfnAlertMessage;
  if (extraout_ST0 != (longdouble)0) {
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
        local_24.z = (peVar1->origin).z + (peVar1->view_ofs).z;
        local_24.y = (peVar1->origin).y + (peVar1->view_ofs).y;
        local_24.x = (peVar1->origin).x + (peVar1->view_ofs).x;
        local_18.z = (gpGlobals->v_forward).z * 1024.0 + local_24.z;
        local_18.y = (gpGlobals->v_forward).y * 1024.0 + local_24.y;
        local_18.x = (gpGlobals->v_forward).x * 1024.0 + local_24.x;
        UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar1->pContainingEntity,&local_5c);
        if (local_5c.pHit == (edict_t *)0x0) {
          local_5c.pHit = peVar4;
        }
        pcVar5 = (*g_engfuncs.pfnTraceTexture)(local_5c.pHit,&local_24.x,&local_18.x);
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


// CBasePlayer::AddPlayerItem  @ 00101d40  (line 4962)

/* DWARF original prototype: int AddPlayerItem(CBasePlayer * this, CBasePlayerItem * pItem) */

int __thiscall CBasePlayer::AddPlayerItem(CBasePlayer *this,CBasePlayerItem *pItem)

{
  char *pcVar1;
  string_t sVar2;
  int iVar3;
  int iVar4;
  CBasePlayerItem *pCVar5;
  
                    /* Unresolved local var: CBasePlayerItem * pInsert@[???] */
  iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x44]
          )(pItem);
  pCVar5 = this->m_rgpPlayerItems[iVar3];
  if (pCVar5 != (CBasePlayerItem *)0x0) {
    pcVar1 = gpGlobals->pStringBase;
    sVar2 = ((pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname;
    do {
      iVar3 = strcmp(pcVar1 + ((pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev
                              )->classname,pcVar1 + sVar2);
      if (iVar3 == 0) {
        iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                  [0x43])(pItem,pCVar5);
        if (iVar3 != 0) {
          (*g_pGameRules->_vptr_CGameRules[0x1e])(g_pGameRules,this,pItem);
          CBasePlayerItem::CheckRespawn(pItem);
          (*(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x4a])(pCVar5);
          pCVar5 = this->m_pActiveItem;
          if (pCVar5 != (CBasePlayerItem *)0x0) {
            (*(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x4a])(pCVar5);
          }
          (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4e]
          )(pItem);
          return 0;
        }
        goto LAB_00101db9;
      }
      pCVar5 = pCVar5->m_pNext;
    } while (pCVar5 != (CBasePlayerItem *)0x0);
  }
  iVar3 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x42]
          )(pItem,this);
  if (iVar3 == 0) {
LAB_00101db9:
    iVar3 = 0;
    if (gEvilImpulse101 != 0) {
      (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x4e])
                (pItem);
      return 0;
    }
  }
  else {
    iVar3 = 1;
    (*g_pGameRules->_vptr_CGameRules[0x1e])(g_pGameRules,this,pItem);
    CBasePlayerItem::CheckRespawn(pItem);
    iVar4 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x44])(pItem);
    pItem->m_pNext = this->m_rgpPlayerItems[iVar4];
    iVar4 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x44])(pItem);
    this->m_rgpPlayerItems[iVar4] = pItem;
    iVar4 = (*g_pGameRules->_vptr_CGameRules[4])(g_pGameRules,this,pItem);
    if ((iVar4 != 0) &&
       (iVar4 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                  [0x46])(pItem), iVar4 != 0)) {
      if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
        (this->m_vecAutoAim).x = 0.0;
        (this->m_vecAutoAim).y = 0.0;
        (this->m_vecAutoAim).z = 0.0;
        (*g_engfuncs.pfnCrosshairAngle)
                  (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
      }
      this->m_fOnTarget = 0;
      pCVar5 = this->m_pActiveItem;
      if (pCVar5 != (CBasePlayerItem *)0x0) {
        (*(pCVar5->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x49])
                  (pCVar5,0);
      }
      iVar3 = 1;
      this->m_pActiveItem = pItem;
      (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x47])
                (pItem);
    }
  }
  return iVar3;
}


// CBasePlayer::RemovePlayerItem  @ 00101ae0  (line 5021)

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
  }
  if (this->m_pLastItem == pItem) {
    this->m_pLastItem = (CBasePlayerItem *)0x0;
  }
  iVar4 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x44]
          )(pItem);
  pCVar1 = this->m_rgpPlayerItems[iVar4];
  if (pCVar1 == pItem) {
    iVar4 = (*(pItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
              [0x44])(pItem);
    this->m_rgpPlayerItems[iVar4] = pItem->m_pNext;
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
    if (pCVar1 != (CBasePlayerItem *)0x0) {
      pCVar3 = pCVar1->m_pNext;
      while( true ) {
        if (pCVar3 == pItem) {
          pCVar1->m_pNext = pItem->m_pNext;
          return 1;
        }
        iVar4 = 0;
        if (pCVar3 == (CBasePlayerItem *)0x0) break;
        pCVar1 = pCVar3;
        pCVar3 = pCVar3->m_pNext;
      }
    }
  }
  return iVar4;
}


// CBasePlayer::GiveAmmo  @ 00101c80  (line 5062)

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
    if (iVar1 == 0) {
      return -1;
    }
    iVar1 = 1;
    do {
      if ((CBasePlayerItem::AmmoInfoArray[iVar1].pszName != (char *)0x0) &&
         (iVar2 = strcasecmp(szName,CBasePlayerItem::AmmoInfoArray[iVar1].pszName), iVar2 == 0)) {
        iVar2 = iMax - this->m_rgAmmo[iVar1];
        if (iCount < iVar2) {
          iVar2 = iCount;
        }
        if (iVar2 < 1) {
          return iVar1;
        }
        this->m_rgAmmo[iVar1] = this->m_rgAmmo[iVar1] + iVar2;
        if (pIndex == (int *)0x0) {
          return iVar1;
        }
        *pIndex = iVar1;
        return iVar1;
      }
                    /* Unresolved local var: int i@[???] */
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x20);
  }
  return -1;
}


// SendAmmoPickupMessage  @ 00107700  (line 5107)

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
        if (iVar2 == 0) goto LAB_00107771;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x20);
  }
  iVar3 = -1;
LAB_00107771:
  (*p_Var1)(iVar3);
  (*g_engfuncs.pfnWriteByte)(AmmoAmount);
                    /* WARNING: Could not recover jumptable at 0x0010778b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::GiveTFAmmo  @ 001077b0  (line 5119)

/* DWARF original prototype: BOOL GiveTFAmmo(CBasePlayer * this, int shells, int nails, int rockets,
   int cells) */

BOOL __thiscall
CBasePlayer::GiveTFAmmo(CBasePlayer *this,int shells,int nails,int rockets,int cells)

{
  _func_void_int *p_Var1;
  int iVar2;
  BOOL BVar3;
  entvars_t *peVar4;
  int iVar5;
  
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_shells;
  iVar2 = shells + (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.ammo_shells;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_shells = iVar2;
  if (iVar5 < iVar2) {
    shells = shells + (iVar5 - iVar2);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = iVar5;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_nails;
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_nails + nails;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_nails = iVar2;
  if (iVar5 < iVar2) {
    nails = nails + (iVar5 - iVar2);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = iVar5;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_rockets;
  iVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_rockets + rockets;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_rockets = iVar2;
  if (iVar5 < iVar2) {
    rockets = rockets + (iVar5 - iVar2);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = iVar5;
  }
  iVar2 = cells + (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.ammo_cells;
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_cells;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_cells = iVar2;
  if (iVar5 < iVar2) {
    cells = cells + (iVar5 - iVar2);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = iVar5;
  }
  BVar3 = 0;
  if (((shells != 0 || nails != 0) || rockets != 0) || cells != 0) {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (0 < shells) {
      iVar5 = 1;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,peVar4->pContainingEntity);
      p_Var1 = g_engfuncs.pfnWriteByte;
      do {
        if (CBasePlayerItem::AmmoInfoArray[iVar5].pszName != (char *)0x0) {
          iVar2 = strcasecmp("buckshot",CBasePlayerItem::AmmoInfoArray[iVar5].pszName);
          if (iVar2 == 0) goto LAB_001078f9;
        }
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      iVar5 = -1;
LAB_001078f9:
      (*p_Var1)(iVar5);
      (*g_engfuncs.pfnWriteByte)(shells);
      (*g_engfuncs.pfnMessageEnd)();
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    if (0 < nails) {
      iVar5 = 1;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,peVar4->pContainingEntity);
      p_Var1 = g_engfuncs.pfnWriteByte;
      do {
        if (CBasePlayerItem::AmmoInfoArray[iVar5].pszName != (char *)0x0) {
          iVar2 = strcasecmp("9mm",CBasePlayerItem::AmmoInfoArray[iVar5].pszName);
          if (iVar2 == 0) goto LAB_00107981;
        }
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      iVar5 = -1;
LAB_00107981:
      (*p_Var1)(iVar5);
      (*g_engfuncs.pfnWriteByte)(nails);
      (*g_engfuncs.pfnMessageEnd)();
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    if (0 < rockets) {
      iVar5 = 1;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,peVar4->pContainingEntity);
      p_Var1 = g_engfuncs.pfnWriteByte;
      do {
        if (CBasePlayerItem::AmmoInfoArray[iVar5].pszName != (char *)0x0) {
          iVar2 = strcasecmp("rockets",CBasePlayerItem::AmmoInfoArray[iVar5].pszName);
          if (iVar2 == 0) goto LAB_00107a01;
        }
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      iVar5 = -1;
LAB_00107a01:
      (*p_Var1)(iVar5);
      (*g_engfuncs.pfnWriteByte)(rockets);
      (*g_engfuncs.pfnMessageEnd)();
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    BVar3 = 1;
    if (0 < cells) {
      iVar5 = 1;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgAmmoPickup,(float *)0x0,peVar4->pContainingEntity);
      p_Var1 = g_engfuncs.pfnWriteByte;
      do {
        if (CBasePlayerItem::AmmoInfoArray[iVar5].pszName != (char *)0x0) {
          iVar2 = strcasecmp("uranium",CBasePlayerItem::AmmoInfoArray[iVar5].pszName);
          if (iVar2 == 0) goto LAB_00107a85;
        }
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0x20);
      iVar5 = -1;
LAB_00107a85:
      (*p_Var1)(iVar5);
      (*g_engfuncs.pfnWriteByte)(cells);
      (*g_engfuncs.pfnMessageEnd)();
      return 1;
    }
  }
  return BVar3;
}


// CBasePlayer::ItemPreFrame  @ 00107af0  (line 5167)

/* DWARF original prototype: void ItemPreFrame(CBasePlayer * this) */

void __thiscall CBasePlayer::ItemPreFrame(CBasePlayer *this)

{
  if (((this->super_CBaseMonster).m_flNextAttack <= 0.0) &&
     (this->m_pActiveItem != (CBasePlayerItem *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00107b1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x4b])();
    return;
  }
  return;
}


// CBasePlayer::ItemPostFrame  @ 00107b30  (line 5188)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ItemPostFrame(CBasePlayer * this) */

void __thiscall CBasePlayer::ItemPostFrame(CBasePlayer *this)

{
  int iVar1;
  
                    /* Unresolved local var: int fInSelect@[???] */
  iVar1 = EHANDLE::operator_int(&this->m_pTank);
  if ((iVar1 == 0) && ((this->super_CBaseMonster).m_flNextAttack <= 0.0)) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x8a])(this);
    if (this->m_pActiveItem != (CBasePlayerItem *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00107b85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
        _vptr_CBaseEntity[0x4c])();
      return;
    }
  }
  return;
}


// CBasePlayer::AmmoInventory  @ 00107b90  (line 5212)

/* DWARF original prototype: int AmmoInventory(CBasePlayer * this, int iAmmoIndex) */

int __thiscall CBasePlayer::AmmoInventory(CBasePlayer *this,int iAmmoIndex)

{
  if (iAmmoIndex != -1) {
    return this->m_rgAmmo[iAmmoIndex];
  }
  return -1;
}


// CBasePlayer::GetAmmoIndex  @ 00107bb0  (line 5222)

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


// CBasePlayer::SendAmmoUpdate  @ 00107c10  (line 5245)

/* DWARF original prototype: void SendAmmoUpdate(CBasePlayer * this) */

void __thiscall CBasePlayer::SendAmmoUpdate(CBasePlayer *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  iVar2 = 0;
  if ((rocket_slot == 0) || (cell_slot == 0)) {
    do {
      while ((iVar1 = iVar2, pcVar5 = CBasePlayerItem::AmmoInfoArray[iVar1].pszName,
             iVar2 = rocket_slot, iVar3 = shell_slot, pcVar5 == (char *)0x0 || (*pcVar5 == '\0'))) {
LAB_00107c46:
        shell_slot = iVar3;
        rocket_slot = iVar2;
        iVar2 = iVar1 + 1;
        if (iVar1 + 1 == 0x20) goto LAB_00107c9f;
      }
      iVar2 = 8;
      bVar7 = false;
      pcVar4 = pcVar5;
      pcVar6 = "rockets";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar7 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      iVar2 = iVar1;
      if (bVar7) goto LAB_00107c46;
      iVar2 = 8;
      bVar7 = false;
      pcVar4 = pcVar5;
      pcVar6 = "uranium";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar7 = *pcVar4 == *pcVar6;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (!bVar7) {
        iVar2 = 9;
        bVar7 = false;
        pcVar4 = pcVar5;
        pcVar6 = "buckshot";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar7 = *pcVar4 == *pcVar6;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar6 + 1;
        } while (bVar7);
        iVar2 = rocket_slot;
        iVar3 = iVar1;
        if (!bVar7) {
          iVar2 = 4;
          pcVar4 = "9mm";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar7 = *pcVar5 == *pcVar4;
            pcVar5 = pcVar5 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar7);
          iVar2 = rocket_slot;
          iVar3 = shell_slot;
          if (bVar7) {
            nail_slot = iVar1;
          }
        }
        goto LAB_00107c46;
      }
      iVar2 = iVar1 + 1;
      cell_slot = iVar1;
    } while (iVar1 + 1 != 0x20);
  }
LAB_00107c9f:
  iVar2 = cell_slot;
                    /* Unresolved local var: int i@[???] */
  this->m_rgAmmo[rocket_slot] =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_rockets;
  this->m_rgAmmo[iVar2] =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_cells;
  this->m_rgAmmo[shell_slot] =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_shells;
  this->m_rgAmmo[nail_slot] =
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.ammo_nails;
  iVar2 = 0;
  do {
    if (this->m_rgAmmo[iVar2] != this->m_rgAmmoLast[iVar2]) {
      this->m_rgAmmoLast[iVar2] = this->m_rgAmmo[iVar2];
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgAmmoX,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(iVar2);
      iVar3 = 0xfe;
      if (this->m_rgAmmo[iVar2] < 0xff) {
        iVar3 = this->m_rgAmmo[iVar2];
      }
      iVar1 = 0;
      if (-1 < iVar3) {
        iVar1 = iVar3;
      }
      (*g_engfuncs.pfnWriteByte)(iVar1);
      (*g_engfuncs.pfnMessageEnd)();
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  return;
}


// CBasePlayer::UpdateClientData  @ 001092c0  (line 5310)

/* DWARF original prototype: void UpdateClientData(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateClientData(CBasePlayer *this)

{
  float fVar1;
  edict_t *peVar2;
  string_t sVar3;
  CBasePlayerItem *pCVar4;
  _func_int_varargs **pp_Var5;
  _func_int_varargs *p_Var6;
  globalvars_t *pgVar7;
  int iVar8;
  entvars_t *peVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  CBasePlayerItem *pCVar14;
  uint uVar15;
  int iVar16;
  float *pfVar17;
  float *pfVar18;
  vec_t vVar19;
  vec_t vVar20;
  uint uVar21;
  undefined4 uStackY_50;
  vec_t local_2c;
  vec_t local_28;
  
  pfVar18 = (float *)&stack0xffffffb4;
  pfVar17 = (float *)&stack0xffffffb4;
  if (this->m_fInitHUD != 0) {
    this->m_fInitHUD = 0;
    gInitHUD = 0;
    uStackY_50 = 0x1097b8;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgResetHUD,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    uStackY_50 = 0x1097c5;
    (*g_engfuncs.pfnWriteByte)(0);
    uStackY_50 = 0x1097cb;
    (*g_engfuncs.pfnMessageEnd)();
    if (this->m_fGameHUDInitialized == 0) {
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      this->m_bSentBuildingEvents = 0;
      uStackY_50 = 0x1098b9;
      (*g_engfuncs.pfnMessageBegin)(1,gmsgInitHUD,(float *)0x0,peVar9->pContainingEntity);
      uStackY_50 = 0x1098bf;
      (*g_engfuncs.pfnMessageEnd)();
      uStackY_50 = 0x1098e8;
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgSetSecAmmoIcon,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      uStackY_50 = 0x1098f5;
      (*g_engfuncs.pfnWriteString)("grenade");
      uStackY_50 = 0x1098fb;
      (*g_engfuncs.pfnMessageEnd)();
      uStackY_50 = 0x10990c;
      (*g_pGameRules->_vptr_CGameRules[0xc])();
      this->m_fGameHUDInitialized = 1;
      this->m_iObserverLastMode = 3;
    }
    uStackY_50 = 0x1097e1;
    TeamFortress_InitStatusBar(this);
    uVar11 = -(((uint)this->m_rgAmmoLast & 0xf) >> 2) & 3;
    if (uVar11 == 0) {
      iVar8 = 0x20;
      uVar12 = 0;
    }
    else {
      uVar12 = 0;
                    /* Unresolved local var: int i@[???] */
      do {
        this->m_rgAmmoLast[uVar12] = -1;
        uVar12 = uVar12 + 1;
        iVar8 = 0x20 - uVar12;
      } while (uVar12 < uVar11);
    }
    uVar21 = 0x20 - uVar11 >> 2;
    if (uVar21 != 0) {
      piVar13 = this->m_rgAmmoLast + uVar11;
      uVar15 = 0;
      do {
        uVar15 = uVar15 + 1;
        *piVar13 = -1;
        piVar13[1] = -1;
        piVar13[2] = -1;
        piVar13[3] = -1;
        piVar13 = piVar13 + 4;
      } while (uVar15 < uVar21);
      uVar12 = uVar12 + uVar21 * 4;
      iVar8 = iVar8 + uVar21 * -4;
      if (0x20 - uVar11 == uVar21 * 4) goto LAB_001092d9;
    }
    iVar16 = 0;
    do {
      *(undefined4 *)((int)this->m_rgAmmoLast + iVar16 + uVar12 * 4) = 0xffffffff;
      iVar16 = iVar16 + 4;
    } while (iVar16 != iVar8 * 4);
  }
LAB_001092d9:
  if (this->delayed_spawn_message != 0) {
    uStackY_50 = 0x10976d;
    UTIL_ShowMessage(gpGlobals->pStringBase + this->delayed_spawn_message,
                     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    this->delayed_spawn_message = 0;
  }
  if (this->m_iHideHUD != this->m_iClientHideHUD) {
    uStackY_50 = 0x10931e;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgHideWeapon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    uStackY_50 = 0x10932d;
    (*g_engfuncs.pfnWriteByte)(this->m_iHideHUD);
    uStackY_50 = 0x109333;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientHideHUD = this->m_iHideHUD;
  }
  if (this->m_iFOV != this->m_iClientFOV) {
    uStackY_50 = 0x109376;
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgSetFOV,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    uStackY_50 = 0x109385;
    (*g_engfuncs.pfnWriteByte)(this->m_iFOV);
    uStackY_50 = 0x10938b;
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientFOV = this->m_iFOV;
  }
  peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar9->health;
  if (fVar1 != (float)this->m_iClientHealth) {
                    /* Unresolved local var: int iHealth@[???] */
    iVar8 = 0xff;
    if ((fVar1 <= 255.0) && (iVar8 = 0, 0.0 <= fVar1)) {
      iVar8 = (int)fVar1;
    }
    if ((0.0 < fVar1) && (fVar1 <= 1.0)) {
      iVar8 = 1;
    }
    uStackY_50 = 0x109666;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgHealth,(float *)0x0,peVar9->pContainingEntity);
    uStackY_50 = 0x10966f;
    (*g_engfuncs.pfnWriteByte)(iVar8);
    uStackY_50 = 0x109675;
    (*g_engfuncs.pfnMessageEnd)();
    peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_iClientHealth = (int)peVar9->health;
  }
  if (((peVar9->dmg_take != 0.0) || (peVar9->dmg_save != 0.0)) ||
     (this->m_bitsHUDDamage != (this->super_CBaseMonster).m_bitsDamageType)) {
                    /* Unresolved local var: Vector damageOrigin@[???]
                       Unresolved local var: edict_t * other@[???] */
    peVar2 = peVar9->dmg_inflictor;
    vVar20 = (peVar9->origin).x;
    vVar19 = (peVar9->origin).y;
    if (peVar2 != (edict_t *)0x0) {
      uStackY_50 = 0x1093fa;
      iVar8 = (*g_engfuncs.pfnEntOffsetOfPEntity)(peVar2);
      pfVar17 = (float *)&stack0xffffffb4;
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if (((iVar8 != 0) && (pfVar17 = (float *)&stack0xffffffb4, peVar2->free == 0)) &&
         (pfVar17 = (float *)&stack0xffffffb4, peVar2->pvPrivateData != (int *)0x0)) {
        uStackY_50 = 0x1096e9;
        (**(code **)(*(int *)peVar2->pvPrivateData + 200))();
        pfVar17 = (float *)&uStackY_50;
        vVar19 = local_28;
        vVar20 = local_2c;
      }
      peVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    peVar2 = peVar9->pContainingEntity;
    *pfVar17 = 1.4013e-45;
    pfVar17[3] = (float)peVar2;
    pfVar17[2] = 0.0;
    pfVar17[1] = (float)gmsgDamage;
    pfVar17[-1] = 1.52252e-39;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar17,(int)pfVar17[1],(float *)pfVar17[2],(edict_t *)pfVar17[3]);
    *pfVar17 = (float)(int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->dmg_save;
    pfVar17[-1] = 1.522549e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar17);
    *pfVar17 = (float)(int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->dmg_take;
    pfVar17[-1] = 1.522577e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar17);
    *pfVar17 = (float)(this->super_CBaseMonster).m_bitsDamageType;
    pfVar17[-1] = 1.522598e-39;
    (*g_engfuncs.pfnWriteLong)((int)*pfVar17);
    *pfVar17 = vVar20;
    pfVar17[-1] = 1.52261e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar17);
    *pfVar17 = vVar19;
    pfVar17[-1] = 1.522623e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar17);
    *pfVar17 = pfVar17[6];
    pfVar17[-1] = 1.522641e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar17);
    pfVar17[-1] = 1.52265e-39;
    (*g_engfuncs.pfnMessageEnd)();
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmg_take = 0.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->dmg_save = 0.0;
    uVar11 = (this->super_CBaseMonster).m_bitsDamageType;
    this->m_bitsHUDDamage = uVar11;
    (this->super_CBaseMonster).m_bitsDamageType = uVar11 & 0x7fc000;
    pfVar18 = pfVar17;
  }
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.tfstate & 1U) !=
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.fClientGrenadePrimed) {
    peVar2 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity;
    pfVar18[2] = 0.0;
    *pfVar18 = 1.4013e-45;
    pfVar18[3] = (float)peVar2;
    pfVar18[1] = (float)gmsgStatusIcon;
    pfVar18[-1] = 1.522805e-39;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar18,(int)pfVar18[1],(float *)pfVar18[2],(edict_t *)pfVar18[3]);
    *pfVar18 = (float)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.tfstate & 1);
    pfVar18[-1] = 1.52283e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar18);
    *pfVar18 = 1.4013e-43;
    pfVar18[-1] = 1.522848e-39;
    (*g_engfuncs.pfnWriteChar)((int)*pfVar18);
    *pfVar18 = 1.33123e-43;
    pfVar18[-1] = 1.522867e-39;
    (*g_engfuncs.pfnWriteChar)((int)*pfVar18);
    sVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.m_iszGrenadeName;
    pcVar10 = "normalgrenade";
    if (sVar3 != 0) {
      pcVar10 = gpGlobals->pStringBase + sVar3;
    }
    *pfVar18 = (float)pcVar10;
    pfVar18[-1] = 1.52292e-39;
    (*g_engfuncs.pfnWriteString)((char *)*pfVar18);
    *pfVar18 = 3.57331e-43;
    pfVar18[-1] = 1.522938e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar18);
    *pfVar18 = 2.24208e-43;
    pfVar18[-1] = 1.522956e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar18);
    *pfVar18 = 0.0;
    pfVar18[-1] = 1.522975e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar18);
    pfVar18[-1] = 1.522983e-39;
    (*g_engfuncs.pfnMessageEnd)();
    uVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.tfstate & 1;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.fClientGrenadePrimed = uVar11;
    if (uVar11 == 0) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_iszGrenadeName = 0;
    }
  }
  pCVar4 = this->m_pActiveItem;
  pCVar14 = (CBasePlayerItem *)0x0;
  if (pCVar4 != (CBasePlayerItem *)0x0) {
    pp_Var5 = (pCVar4->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity;
    pfVar18[1] = (float)this;
    *pfVar18 = (float)pCVar4;
    p_Var6 = pp_Var5[0x52];
    pfVar18[-1] = 1.523053e-39;
    (*p_Var6)();
    pCVar14 = this->m_pActiveItem;
  }
  pgVar7 = gpGlobals;
  this->m_pClientActiveItem = pCVar14;
  if (this->m_flNextSBarUpdateTime < pgVar7->time) {
    *pfVar18 = (float)this;
    pfVar18[-1] = 1.52311e-39;
    UpdateLowPriorityClientData((CBasePlayer *)*pfVar18);
    *pfVar18 = (float)this;
    pfVar18[-1] = 1.523122e-39;
    TeamFortress_UpdateStatusBar((CBasePlayer *)*pfVar18);
    this->m_flNextSBarUpdateTime = gpGlobals->time + 0.2;
  }
  *pfVar18 = (float)this;
  pfVar18[-1] = 1.52316e-39;
  UpdateClientCommandMenu((CBasePlayer *)*pfVar18);
  return;
}


// CBasePlayer::UpdateLowPriorityClientData  @ 00107dc0  (line 5453)

/* DWARF original prototype: void UpdateLowPriorityClientData(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateLowPriorityClientData(CBasePlayer *this)

{
  CBasePlayerItem *pCVar1;
  float fVar2;
  _func_void_int *p_Var3;
  int iVar4;
  entvars_t *peVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  
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
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor;
  if (((int)peVar5->armorvalue == this->m_iClientBattery) && ((int)fVar6 == this->m_iMaxArmor)) {
    fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.no_grenades_1;
    fVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.cl_no_grenades_1;
    bVar13 = fVar2 == fVar6;
    if (NAN(fVar2) || NAN(fVar6)) goto LAB_001084a5;
LAB_00107ec8:
    if (!bVar13) goto LAB_001084a5;
    fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.no_grenades_2;
    fVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.cl_no_grenades_2;
    bVar13 = fVar2 == fVar6;
    if (!NAN(fVar2) && !NAN(fVar6)) goto LAB_00107ee5;
LAB_00108508:
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.cl_no_grenades_2 = fVar2;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgGrenades,(float *)0x0,peVar5->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.no_grenades_2);
    (*g_engfuncs.pfnMessageEnd)();
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else {
    this->m_iClientBattery = (int)peVar5->armorvalue;
    this->m_iMaxArmor = (int)fVar6;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgBattery,(float *)0x0,peVar5->pContainingEntity);
    (*g_engfuncs.pfnWriteShort)
              ((int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->armorvalue);
    (*g_engfuncs.pfnWriteShort)
              ((int)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.maxarmor);
    (*g_engfuncs.pfnMessageEnd)();
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.no_grenades_1;
    fVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.cl_no_grenades_1;
    bVar13 = fVar2 == fVar6;
    if (!NAN(fVar2) && !NAN(fVar6)) goto LAB_00107ec8;
LAB_001084a5:
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.cl_no_grenades_1 = fVar2;
    (*g_engfuncs.pfnMessageBegin)(1,gmsgGrenades,(float *)0x0,peVar5->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)
              ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.no_grenades_1);
    (*g_engfuncs.pfnMessageEnd)();
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.no_grenades_2;
    fVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.cl_no_grenades_2;
    bVar13 = fVar2 == fVar6;
    if (NAN(fVar2) || NAN(fVar6)) goto LAB_00108508;
LAB_00107ee5:
    if (!bVar13) goto LAB_00108508;
  }
  if (((((float)this->m_iClientFrags != peVar5->frags) || (this->m_iClientDeaths != this->m_iDeaths)
       ) || (this->m_iClientPlayerClass != peVar5->playerclass)) ||
     (this->m_iClientTeam != peVar5->team)) {
    (*g_engfuncs.pfnMessageBegin)(2,gmsgScoreInfo,(float *)0x0,(edict_t *)0x0);
    p_Var3 = g_engfuncs.pfnWriteByte;
    iVar4 = (*g_engfuncs.pfnIndexOfEdict)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    (*p_Var3)(iVar4);
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
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    this->m_iClientPlayerClass = peVar5->playerclass;
    this->m_iClientTeam = peVar5->team;
    this->m_iClientDeaths = this->m_iDeaths;
    this->m_iClientFrags = (int)peVar5->frags;
  }
  if ((this->m_iTrain & 0xc0) != 0) {
    (*g_engfuncs.pfnMessageBegin)(1,gmsgTrain,(float *)0x0,peVar5->pContainingEntity);
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
  uVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  if (((uVar8 & 0x8000) != 0) !=
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.clientTranq != 0.0)) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)
              ((uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.tfstate & 0x8000) != 0));
    (*g_engfuncs.pfnWriteString)("dmg_tranq");
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0xa0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    uVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
    fVar6 = 0.0;
    if ((uVar8 & 0x8000) != 0) {
      fVar6 = 1.0;
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.clientTranq = fVar6;
  }
  if (((uVar8 & 0x4000) != 0) !=
      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.clientHalluc != 0.0)) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgStatusIcon,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)
              ((uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.tfstate & 0x4000) != 0));
    (*g_engfuncs.pfnWriteString)("dmg_haluc");
    (*g_engfuncs.pfnWriteByte)(0xff);
    (*g_engfuncs.pfnWriteByte)(0xa0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnMessageEnd)();
    fVar6 = 0.0;
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.tfstate & 0x4000) != 0) {
      fVar6 = 1.0;
    }
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.clientHalluc = fVar6;
  }
  uVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.items;
  uVar9 = this->m_iClientItems;
  if (uVar8 == uVar9) goto LAB_0010821f;
                    /* Unresolved local var: int changeditems@[???]
                       Unresolved local var: int newitems@[???]
                       Unresolved local var: int removeditems@[???] */
  uVar12 = (uVar9 ^ uVar8) & uVar9;
  uVar9 = (uVar9 ^ uVar8) & uVar8;
  this->m_iClientItems = uVar8;
  if ((uVar9 & 0x20000) == 0) {
    if ((uVar12 & 0x20000) != 0) {
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgStatusIcon,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnWriteString)("flag_blue");
      (*g_engfuncs.pfnMessageEnd)();
    }
    if ((uVar9 & 0x40000) != 0) goto LAB_001087e6;
LAB_001081e3:
    if ((uVar12 & 0x40000) != 0) {
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
    if ((uVar9 & 0x40000) == 0) goto LAB_001081e3;
LAB_001087e6:
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
  if ((uVar9 & 0x1000000) == 0) {
    if ((uVar12 & 0x1000000) != 0) {
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
  if ((uVar9 & 0x2000000) == 0) {
    if ((uVar12 & 0x2000000) != 0) {
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
LAB_0010821f:
  if (this->m_fKnownItem == 0) {
                    /* Unresolved local var: int i@[???] */
    iVar4 = 0;
    this->m_fKnownItem = 1;
                    /* Unresolved local var: ItemInfo * II@[???]
                       Unresolved local var: char * pszName@[???] */
    do {
      if (CBasePlayerItem::ItemInfoArray[iVar4].iId != 0) {
        pcVar10 = CBasePlayerItem::ItemInfoArray[iVar4].pszName;
        if (pcVar10 == (char *)0x0) {
          pcVar10 = "Empty";
        }
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgWeaponList,(float *)0x0,
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        (*g_engfuncs.pfnWriteString)(pcVar10);
        p_Var3 = g_engfuncs.pfnWriteByte;
        pcVar10 = CBasePlayerItem::ItemInfoArray[iVar4].pszAmmo1;
                    /* Unresolved local var: int i@[???] */
        if (pcVar10 == (char *)0x0) {
          iVar11 = -1;
        }
        else {
          iVar11 = 1;
          do {
            if ((CBasePlayerItem::AmmoInfoArray[iVar11].pszName != (char *)0x0) &&
               (iVar7 = strcasecmp(pcVar10,CBasePlayerItem::AmmoInfoArray[iVar11].pszName),
               iVar7 == 0)) goto LAB_001082f3;
            iVar11 = iVar11 + 1;
          } while (iVar11 != 0x20);
          iVar11 = -1;
        }
LAB_001082f3:
        (*p_Var3)(iVar11);
        (*g_engfuncs.pfnWriteByte)(CBasePlayerItem::ItemInfoArray[iVar4].iAmmo1);
        p_Var3 = g_engfuncs.pfnWriteByte;
        pcVar10 = CBasePlayerItem::ItemInfoArray[iVar4].pszAmmo2;
                    /* Unresolved local var: int i@[???] */
        if (pcVar10 == (char *)0x0) {
          iVar11 = -1;
        }
        else {
          iVar11 = 1;
          do {
            if ((CBasePlayerItem::AmmoInfoArray[iVar11].pszName != (char *)0x0) &&
               (iVar7 = strcasecmp(pcVar10,CBasePlayerItem::AmmoInfoArray[iVar11].pszName),
               iVar7 == 0)) goto LAB_0010835b;
            iVar11 = iVar11 + 1;
          } while (iVar11 != 0x20);
          iVar11 = -1;
        }
LAB_0010835b:
        (*p_Var3)(iVar11);
        (*g_engfuncs.pfnWriteByte)(CBasePlayerItem::ItemInfoArray[iVar4].iAmmo2);
        (*g_engfuncs.pfnWriteByte)(CBasePlayerItem::ItemInfoArray[iVar4].iSlot);
        (*g_engfuncs.pfnWriteByte)(CBasePlayerItem::ItemInfoArray[iVar4].iPosition);
        (*g_engfuncs.pfnWriteByte)(CBasePlayerItem::ItemInfoArray[iVar4].iId);
        (*g_engfuncs.pfnWriteByte)(CBasePlayerItem::ItemInfoArray[iVar4].iFlags);
        (*g_engfuncs.pfnMessageEnd)();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x20);
  }
  SendAmmoUpdate(this);
                    /* Unresolved local var: int i@[???] */
  pCVar1 = this->m_rgpPlayerItems[0];
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x52])
              (pCVar1,this);
  }
  pCVar1 = this->m_rgpPlayerItems[1];
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x52])
              (pCVar1,this);
  }
  pCVar1 = this->m_rgpPlayerItems[2];
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x52])
              (pCVar1,this);
  }
  pCVar1 = this->m_rgpPlayerItems[3];
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x52])
              (pCVar1,this);
  }
  pCVar1 = this->m_rgpPlayerItems[4];
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x52])
              (pCVar1,this);
  }
  pCVar1 = this->m_rgpPlayerItems[5];
  if (pCVar1 != (CBasePlayerItem *)0x0) {
    (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x52])
              (pCVar1,this);
  }
  return;
}


// CBasePlayer::UpdateClientCommandMenu  @ 001089e0  (line 5715)

/* DWARF original prototype: void UpdateClientCommandMenu(CBasePlayer * this) */

void __thiscall CBasePlayer::UpdateClientCommandMenu(CBasePlayer *this)

{
  entvars_t *peVar1;
  BOOL BVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  
                    /* Unresolved local var: int iState@[???] */
  if (this->m_bUpdatedCommandMenu != 0) goto LAB_001089f7;
                    /* Unresolved local var: int i@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_bUpdatedCommandMenu = 1;
  (*g_engfuncs.pfnMessageBegin)(1,gmsgValidClasses,(float *)0x0,peVar1->pContainingEntity);
  BVar2 = TeamFortress_TeamIsCivilian(0.0);
  if (BVar2 == 0) {
    (*g_engfuncs.pfnWriteShort)(illegalclasses[0]);
    BVar2 = TeamFortress_TeamIsCivilian(1.0);
    if (BVar2 == 0) goto LAB_00108d7a;
LAB_001090c9:
    (*g_engfuncs.pfnWriteShort)(-1);
    BVar2 = TeamFortress_TeamIsCivilian(2.0);
    if (BVar2 != 0) goto LAB_001090ea;
LAB_00108d9c:
    (*g_engfuncs.pfnWriteShort)(illegalclasses[2]);
    BVar2 = TeamFortress_TeamIsCivilian(3.0);
    if (BVar2 == 0) goto LAB_00108dbe;
LAB_0010910b:
    (*g_engfuncs.pfnWriteShort)(-1);
    BVar2 = TeamFortress_TeamIsCivilian(4.0);
    if (BVar2 == 0) goto LAB_0010912c;
LAB_00108de0:
    (*g_engfuncs.pfnWriteShort)(-1);
  }
  else {
    (*g_engfuncs.pfnWriteShort)(-1);
    BVar2 = TeamFortress_TeamIsCivilian(1.0);
    if (BVar2 != 0) goto LAB_001090c9;
LAB_00108d7a:
    (*g_engfuncs.pfnWriteShort)(illegalclasses[1]);
    BVar2 = TeamFortress_TeamIsCivilian(2.0);
    if (BVar2 == 0) goto LAB_00108d9c;
LAB_001090ea:
    (*g_engfuncs.pfnWriteShort)(-1);
    BVar2 = TeamFortress_TeamIsCivilian(3.0);
    if (BVar2 != 0) goto LAB_0010910b;
LAB_00108dbe:
    (*g_engfuncs.pfnWriteShort)(illegalclasses[3]);
    BVar2 = TeamFortress_TeamIsCivilian(4.0);
    if (BVar2 != 0) goto LAB_00108de0;
LAB_0010912c:
    (*g_engfuncs.pfnWriteShort)(illegalclasses[4]);
  }
  (*g_engfuncs.pfnMessageEnd)();
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgTeamNames,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)((int)number_of_teams);
                    /* Unresolved local var: char * teamName@[???] */
  pcVar3 = GetTeamName(1);
  iVar4 = strcasecmp(pcVar3,"Blue");
  if (iVar4 == 0) {
    (*g_engfuncs.pfnWriteString)("#Team_Blue");
  }
  else {
    iVar4 = strcasecmp(pcVar3,"Red");
    if (iVar4 == 0) {
      (*g_engfuncs.pfnWriteString)("#Team_Red");
    }
    else {
      iVar4 = strcasecmp(pcVar3,"Yellow");
      if (iVar4 == 0) {
        (*g_engfuncs.pfnWriteString)("#Team_Yellow");
      }
      else {
        iVar4 = strcasecmp(pcVar3,"Green");
        if (iVar4 == 0) {
          (*g_engfuncs.pfnWriteString)("#Team_Green");
        }
        else {
          (*g_engfuncs.pfnWriteString)(pcVar3);
        }
      }
    }
  }
  pcVar3 = GetTeamName(2);
  iVar4 = strcasecmp(pcVar3,"Blue");
  if (iVar4 == 0) {
    (*g_engfuncs.pfnWriteString)("#Team_Blue");
  }
  else {
    iVar4 = strcasecmp(pcVar3,"Red");
    if (iVar4 == 0) {
      (*g_engfuncs.pfnWriteString)("#Team_Red");
    }
    else {
      iVar4 = strcasecmp(pcVar3,"Yellow");
      if (iVar4 == 0) {
        (*g_engfuncs.pfnWriteString)("#Team_Yellow");
      }
      else {
        iVar4 = strcasecmp(pcVar3,"Green");
        if (iVar4 == 0) {
          (*g_engfuncs.pfnWriteString)("#Team_Green");
        }
        else {
          (*g_engfuncs.pfnWriteString)(pcVar3);
        }
      }
    }
  }
  pcVar3 = GetTeamName(3);
  iVar4 = strcasecmp(pcVar3,"Blue");
  if (iVar4 == 0) {
    (*g_engfuncs.pfnWriteString)("#Team_Blue");
  }
  else {
    iVar4 = strcasecmp(pcVar3,"Red");
    if (iVar4 == 0) {
      (*g_engfuncs.pfnWriteString)("#Team_Red");
    }
    else {
      iVar4 = strcasecmp(pcVar3,"Yellow");
      if (iVar4 == 0) {
        (*g_engfuncs.pfnWriteString)("#Team_Yellow");
      }
      else {
        iVar4 = strcasecmp(pcVar3,"Green");
        if (iVar4 == 0) {
          (*g_engfuncs.pfnWriteString)("#Team_Green");
        }
        else {
          (*g_engfuncs.pfnWriteString)(pcVar3);
        }
      }
    }
  }
  pcVar3 = GetTeamName(4);
  iVar4 = strcasecmp(pcVar3,"Blue");
  if (iVar4 == 0) {
    (*g_engfuncs.pfnWriteString)("#Team_Blue");
  }
  else {
    iVar4 = strcasecmp(pcVar3,"Red");
    if (iVar4 == 0) {
      (*g_engfuncs.pfnWriteString)("#Team_Red");
    }
    else {
      iVar4 = strcasecmp(pcVar3,"Yellow");
      if (iVar4 == 0) {
        (*g_engfuncs.pfnWriteString)("#Team_Yellow");
      }
      else {
        iVar4 = strcasecmp(pcVar3,"Green");
        if (iVar4 == 0) {
          (*g_engfuncs.pfnWriteString)("#Team_Green");
        }
        else {
          (*g_engfuncs.pfnWriteString)(pcVar3);
        }
      }
    }
  }
  (*g_engfuncs.pfnMessageEnd)();
  g_ClientsAllowSpectator = (int)allow_spectators.value;
  (*g_engfuncs.pfnMessageBegin)
            (1,gmsgAllowSpec,(float *)0x0,
             ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity);
  (*g_engfuncs.pfnWriteByte)((uint)(g_ClientsAllowSpectator != 0));
  (*g_engfuncs.pfnMessageEnd)();
LAB_001089f7:
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
  uVar5 = (uint)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.is_building != 0);
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_sentry == 0.0) {
    if (0x81 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells) {
      uVar5 = uVar5 | 0x10;
    }
  }
  else {
    uVar5 = uVar5 | 4;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_dispenser == 0.0) {
    if (99 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.ammo_cells) {
      uVar5 = uVar5 | 8;
    }
  }
  else {
    uVar5 = uVar5 | 2;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_entry_teleporter == 0.0) {
    if (0x7c < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells) {
      uVar5 = uVar5 | 0x80;
    }
  }
  else {
    uVar5 = uVar5 | 0x20;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.has_exit_teleporter == 0.0) {
    if (0x7c < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells) {
      uVar5 = uVar5 | 0x100;
    }
  }
  else {
    uVar5 = uVar5 | 0x40;
  }
  if (this->m_iClientBuildState != uVar5) {
    (*g_engfuncs.pfnMessageBegin)
              (1,gmsgBuildState,(float *)0x0,
               ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity);
    (*g_engfuncs.pfnWriteShort)(uVar5);
    (*g_engfuncs.pfnMessageEnd)();
    this->m_iClientBuildState = uVar5;
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
  uVar5 = 1;
  if (allow_spectators.value == 0.0) {
    uVar5 = (uint)NAN(allow_spectators.value);
  }
  (*g_engfuncs.pfnWriteByte)(uVar5);
  (*g_engfuncs.pfnMessageEnd)();
  g_ClientsAllowSpectator = (int)allow_spectators.value;
  return;
}


// CBasePlayer::FBecomeProne  @ 001001f0  (line 5853)

/* DWARF original prototype: BOOL FBecomeProne(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::FBecomeProne(CBasePlayer *this)

{
  this->m_afPhysicsFlags = this->m_afPhysicsFlags | 4;
  return 1;
}


// CBasePlayer::BarnacleVictimBitten  @ 00100210  (line 5864)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void BarnacleVictimBitten(CBasePlayer * this, entvars_t * pevBarnacle)
    */

void __thiscall CBasePlayer::BarnacleVictimBitten(CBasePlayer *this,entvars_t *pevBarnacle)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0xd])
            (this,pevBarnacle,pevBarnacle,peVar1->health + peVar1->armorvalue,0x2004);
  return;
}


// CBasePlayer::BarnacleVictimReleased  @ 00100250  (line 5873)

/* DWARF original prototype: void BarnacleVictimReleased(CBasePlayer * this) */

void __thiscall CBasePlayer::BarnacleVictimReleased(CBasePlayer *this)

{
  this->m_afPhysicsFlags = this->m_afPhysicsFlags & 0xfffffffb;
  return;
}


// CBasePlayer::Illumination  @ 00100260  (line 5883)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int Illumination(CBasePlayer * this) */

int __thiscall CBasePlayer::Illumination(CBasePlayer *this)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int iIllum@[DW_OP_reg2(EDX)] */
  iVar1 = (*g_engfuncs.pfnGetEntityIllum)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar1 = this->m_iWeaponFlash + iVar1;
  iVar2 = 0xff;
  if (iVar1 < 0x100) {
    iVar2 = iVar1;
  }
  return iVar2;
}


// CBasePlayer::EnableControl  @ 0010a740  (line 5895)

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


// CBasePlayer::GetAutoaimVector  @ 0010a770  (line 5922)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Vector GetAutoaimVector(CBasePlayer * this, float flDelta) */

Vector * __thiscall
CBasePlayer::GetAutoaimVector(Vector *__return_storage_ptr__,CBasePlayer *this,float flDelta)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  Vector local_18;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.z = (peVar1->v_angle).z + (peVar1->punchangle).z;
  local_18.y = (peVar1->v_angle).y + (peVar1->punchangle).y;
  local_18.x = (peVar1->v_angle).x + (peVar1->punchangle).x;
  UTIL_MakeVectors(&local_18);
  pgVar2 = gpGlobals;
  __return_storage_ptr__->x = (gpGlobals->v_forward).x;
  __return_storage_ptr__->y = (pgVar2->v_forward).y;
  __return_storage_ptr__->z = (pgVar2->v_forward).z;
  return __return_storage_ptr__;
}


// CBasePlayer::AutoaimDeflection  @ 0010a7d0  (line 5930)

/* DWARF original prototype: Vector AutoaimDeflection(CBasePlayer * this, Vector * vecSrc, float
   flDist, float flDelta) */

Vector * __thiscall
CBasePlayer::AutoaimDeflection
          (Vector *__return_storage_ptr__,CBasePlayer *this,Vector *vecSrc,float flDist,
          float flDelta)

{
                    /* Unresolved local var: edict_t * pEdict@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: float bestdot@[???]
                       Unresolved local var: Vector bestdir@[???]
                       Unresolved local var: edict_t * bestent@[???]
                       Unresolved local var: TraceResult tr@[???] */
  (*g_engfuncs.pfnPEntityOfEntIndex)(1);
  this->m_fOnTarget = 0;
  __return_storage_ptr__->x = g_vecZero.x;
  __return_storage_ptr__->y = g_vecZero.y;
  __return_storage_ptr__->z = g_vecZero.z;
  return __return_storage_ptr__;
}


// CBasePlayer::ResetAutoaim  @ 0010a820  (line 6054)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ResetAutoaim(CBasePlayer * this) */

void __thiscall CBasePlayer::ResetAutoaim(CBasePlayer *this)

{
  if (((this->m_vecAutoAim).x == 0.0) && ((this->m_vecAutoAim).y == 0.0)) {
    this->m_fOnTarget = 0;
    return;
  }
  (this->m_vecAutoAim).x = 0.0;
  (this->m_vecAutoAim).y = 0.0;
  (this->m_vecAutoAim).z = 0.0;
  (*g_engfuncs.pfnCrosshairAngle)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
  this->m_fOnTarget = 0;
  return;
}


// CBasePlayer::SetCustomDecalFrames  @ 0010a8c0  (line 6072)

/* DWARF original prototype: void SetCustomDecalFrames(CBasePlayer * this, int nFrames) */

void __thiscall CBasePlayer::SetCustomDecalFrames(CBasePlayer *this,int nFrames)

{
  if (6 < nFrames - 1U) {
    nFrames = -1;
  }
  this->m_nCustomSprayFrames = nFrames;
  return;
}


// CBasePlayer::GetCustomDecalFrames  @ 0010a8e0  (line 6089)

/* DWARF original prototype: int GetCustomDecalFrames(CBasePlayer * this) */

int __thiscall CBasePlayer::GetCustomDecalFrames(CBasePlayer *this)

{
  return this->m_nCustomSprayFrames;
}


// CBasePlayer::DropPlayerItem  @ 0010a8f0  (line 6097)

/* DWARF original prototype: void DropPlayerItem(CBasePlayer * this, char * pszItemName) */

void __thiscall CBasePlayer::DropPlayerItem(CBasePlayer *this,char *pszItemName)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  byte bVar6;
  globalvars_t *pgVar7;
  int iVar8;
  CWeaponBox *this_00;
  int iVar9;
  CBasePlayerItem *pWeapon;
  CBasePlayer *pCVar10;
  undefined1 local_5c [8];
  char *local_54;
  byte local_38;
  Vector local_28 [2];
  
                    /* Unresolved local var: CBasePlayerItem * pWeapon@[???]
                       Unresolved local var: int i@[???] */
  iVar8 = (*g_pGameRules->_vptr_CGameRules[6])(g_pGameRules);
  if (iVar8 == 0) {
    return;
  }
  if (0.0 < weaponstay.value) {
    return;
  }
  pCVar10 = this;
  if (*pszItemName == '\0') {
    pszItemName = (char *)0x0;
  }
LAB_0010a940:
  pgVar7 = gpGlobals;
  pWeapon = pCVar10->m_rgpPlayerItems[0];
  if (pWeapon != (CBasePlayerItem *)0x0) {
    if (pszItemName == (char *)0x0) {
      do {
        if (this->m_pActiveItem == pWeapon) goto joined_r0x0010a989;
        pWeapon = pWeapon->m_pNext;
      } while (pWeapon != (CBasePlayerItem *)0x0);
    }
    else {
      do {
        iVar8 = strcmp(pszItemName,
                       pgVar7->pStringBase +
                       ((pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->
                       classname);
        if (iVar8 == 0) goto joined_r0x0010a989;
        pWeapon = pWeapon->m_pNext;
      } while (pWeapon != (CBasePlayerItem *)0x0);
    }
  }
  goto LAB_0010a98b;
joined_r0x0010a989:
  if (pWeapon != (CBasePlayerItem *)0x0) {
    iVar8 = (*g_pGameRules->_vptr_CGameRules[5])(g_pGameRules,this,pWeapon);
    if (iVar8 == 0) {
      return;
    }
    UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->angles);
    bVar6 = (byte)pWeapon->m_iId & 0x1f;
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->weapons;
    *piVar1 = *piVar1 & (-2 << bVar6 | 0xfffffffeU >> 0x20 - bVar6);
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_28[0].z = (gpGlobals->v_forward).z * 10.0 + (peVar5->origin).z;
    local_28[0].y = (gpGlobals->v_forward).y * 10.0 + (peVar5->origin).y;
    local_28[0].x = (gpGlobals->v_forward).x * 10.0 + (peVar5->origin).x;
    this_00 = (CWeaponBox *)
              CBaseEntity::Create("weaponbox",local_28,&peVar5->angles,peVar5->pContainingEntity);
    (((this_00->super_CBaseEntity).pev)->angles).x = 0.0;
    (((this_00->super_CBaseEntity).pev)->angles).z = 0.0;
    CWeaponBox::PackWeapon(this_00,pWeapon);
    peVar5 = (this_00->super_CBaseEntity).pev;
    fVar2 = (gpGlobals->v_forward).z;
    fVar3 = (gpGlobals->v_forward).y;
    fVar4 = (gpGlobals->v_forward).x;
    (peVar5->velocity).x = fVar4 * 100.0 + fVar4 * 300.0;
    (peVar5->velocity).y = fVar3 * 300.0 + fVar3 * 100.0;
    (peVar5->velocity).z = fVar2 * 100.0 + fVar2 * 300.0;
    (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity[0x45])
              (pWeapon,local_5c);
                    /* Unresolved local var: int i@[???] */
    if (local_54 == (char *)0x0) {
      return;
    }
    iVar8 = 1;
    while ((CBasePlayerItem::AmmoInfoArray[iVar8].pszName == (char *)0x0 ||
           (iVar9 = strcasecmp(local_54,CBasePlayerItem::AmmoInfoArray[iVar8].pszName), iVar9 != 0))
          ) {
      iVar8 = iVar8 + 1;
      if (iVar8 == 0x20) {
        return;
      }
    }
    if ((local_38 & 0x10) != 0) {
      CWeaponBox::PackAmmo
                (this_00,(int)local_54 - (int)gpGlobals->pStringBase,this->m_rgAmmo[iVar8]);
      this->m_rgAmmo[iVar8] = 0;
      return;
    }
    CWeaponBox::PackAmmo
              (this_00,(int)local_54 - (int)gpGlobals->pStringBase,this->m_rgAmmo[iVar8] / 2);
    this->m_rgAmmo[iVar8] = this->m_rgAmmo[iVar8] / 2;
    return;
  }
LAB_0010a98b:
                    /* Unresolved local var: CWeaponBox * pWeaponBox@[???]
                       Unresolved local var: ItemInfo info@[???]
                       Unresolved local var: int iAmmoIndex@[DW_OP_reg3(EBX)] */
  pCVar10 = (CBasePlayer *)
            &(pCVar10->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  if (pCVar10 ==
      (CBasePlayer *)
      &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.m_pfnTouch) {
    return;
  }
  goto LAB_0010a940;
}


// CBasePlayer::HasPlayerItem  @ 0010aba0  (line 6196)

/* DWARF original prototype: BOOL HasPlayerItem(CBasePlayer * this, CBasePlayerItem * pCheckItem) */

BOOL __thiscall CBasePlayer::HasPlayerItem(CBasePlayer *this,CBasePlayerItem *pCheckItem)

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


// CBasePlayer::HasNamedPlayerItem  @ 0010ac20  (line 6215)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL HasNamedPlayerItem(CBasePlayer * this, char * pszItemName) */

BOOL __thiscall CBasePlayer::HasNamedPlayerItem(CBasePlayer *this,char *pszItemName)

{
  char *pcVar1;
  int iVar2;
  CBasePlayerItem *pCVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
                    /* Unresolved local var: CBasePlayerItem * pItem@[???]
                       Unresolved local var: int i@[???] */
    pCVar3 = this->m_rgpPlayerItems[iVar4];
    if (pCVar3 != (CBasePlayerItem *)0x0) {
      pcVar1 = gpGlobals->pStringBase;
      do {
        iVar2 = strcmp(pszItemName,
                       pcVar1 + ((pCVar3->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                                pev)->classname);
        if (iVar2 == 0) {
          return 1;
        }
        pCVar3 = pCVar3->m_pNext;
      } while (pCVar3 != (CBasePlayerItem *)0x0);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 6);
  return 0;
}


// CBasePlayer::SwitchWeapon  @ 0010ac90  (line 6240)

/* DWARF original prototype: BOOL SwitchWeapon(CBasePlayer * this, CBasePlayerItem * pWeapon) */

BOOL __thiscall CBasePlayer::SwitchWeapon(CBasePlayer *this,CBasePlayerItem *pWeapon)

{
  CBasePlayerItem *pCVar1;
  int iVar2;
  
  iVar2 = (*(pWeapon->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x46])(pWeapon);
  if (iVar2 == 0) {
    return 0;
  }
  if (((this->m_vecAutoAim).x != 0.0) || ((this->m_vecAutoAim).y != 0.0)) {
    (this->m_vecAutoAim).x = 0.0;
    (this->m_vecAutoAim).y = 0.0;
    (this->m_vecAutoAim).z = 0.0;
    (*g_engfuncs.pfnCrosshairAngle)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->pContainingEntity,0.0,0.0);
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
  return 1;
}


// CBasePlayer::SwitchWeapon  @ 0010ad90  (line 6263)

/* DWARF original prototype: BOOL SwitchWeapon(CBasePlayer * this, char * szWeaponName) */

BOOL __thiscall CBasePlayer::SwitchWeapon(CBasePlayer *this,char *szWeaponName)

{
  CBasePlayerItem *pCVar1;
  CBasePlayerItem *pCVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???]
                       Unresolved local var: int i@[???] */
    for (pCVar1 = this->m_rgpPlayerItems[iVar4]; pCVar1 != (CBasePlayerItem *)0x0;
        pCVar1 = pCVar1->m_pNext) {
                    /* Unresolved local var: ItemInfo * Info@[???] */
      if ((CBasePlayerItem::ItemInfoArray[pCVar1->m_iId].pszName != (char *)0x0) &&
         (iVar3 = strcmp(CBasePlayerItem::ItemInfoArray[pCVar1->m_iId].pszName,szWeaponName),
         iVar3 == 0)) {
        iVar4 = (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x46])(pCVar1);
        if (iVar4 == 0) {
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
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 6) {
      return 0;
    }
  } while( true );
}


// CDeadHEV::Classify  @ 001139e0  (line 6292)

/* DWARF original prototype: int Classify(CDeadHEV * this) */

int __thiscall CDeadHEV::Classify(CDeadHEV *this)

{
  return 4;
}


// CDeadHEV::KeyValue  @ 00100bd0  (line 6303)

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


// monster_hevsuit_dead  @ 0010aed0  (line 6313)

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
  *puVar1 = &PTR__CDeadHEV_00189608;
  puVar1[1] = pev;
  return;
}


// CDeadHEV::Spawn  @ 00100640  (line 6319)

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
  iVar1 = this->m_iPose;
  (this->super_CBaseMonster).m_bloodColor = 0xf7;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar1 = CBaseAnimating::LookupSequence((CBaseAnimating *)this,m_szPoses[iVar1]);
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
                    /* WARNING: Could not recover jumptable at 0x001006f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x49])();
  return;
}


// player_weaponstrip  @ 0010af40  (line 6353)

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
  *puVar1 = &PTR__CStripWeapons_00189828;
  puVar1[1] = pev;
  return;
}


// CStripWeapons::Use  @ 0010a6c0  (line 6356)

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
       (peVar1->pvPrivateData == (void *)0x0)))))) {
    return;
  }
  CBasePlayer::RemoveAllItems((CBasePlayer *)this,(BOOL)pActivator);
  return;
}


// player_loadsaved  @ 0010afb0  (line 6399)

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
  *puVar1 = &PTR__CRevertSaved_00189948;
  puVar1[1] = pev;
  return;
}


// CRevertSaved::Restore  @ 001009c0  (line 6407)

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


// CRevertSaved::Save  @ 00100a20  (line 6407)

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


// CRevertSaved::KeyValue  @ 00100c60  (line 6410)

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


// CRevertSaved::Use  @ 001005d0  (line 6436)

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


// CRevertSaved::MessageThink  @ 00100d90  (line 6444)

/* DWARF original prototype: void MessageThink(CRevertSaved * this) */

void __thiscall CRevertSaved::MessageThink(CRevertSaved *this)

{
  float fVar1;
  
                    /* Unresolved local var: float nextThink@[???] */
  UTIL_ShowMessageAll(gpGlobals->pStringBase +
                      ((this->super_CPointEntity).super_CBaseEntity.pev)->message);
  fVar1 = this->m_loadTime - this->m_messageTime;
  if (fVar1 <= 0.0) {
    if (gpGlobals->deathmatch == 0.0) {
                    /* WARNING: Could not recover jumptable at 0x00100e14. Too many branches */
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


// CRevertSaved::LoadThink  @ 00100990  (line 6459)

/* DWARF original prototype: void LoadThink(CRevertSaved * this) */

void __thiscall CRevertSaved::LoadThink(CRevertSaved *this)

{
  if (gpGlobals->deathmatch != 0.0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x001009b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnServerCommand)("reload\n");
  return;
}


// CInfoIntermission::Spawn  @ 00100560  (line 6476)

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


// CInfoIntermission::Think  @ 001013f0  (line 6487)

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
  Vector local_2c;
  Vector local_18;
  
                    /* Unresolved local var: edict_t * pTarget@[DW_OP_reg3(EBX)] */
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
    local_2c.z = SQRT(__x);
    if (NAN(local_2c.z)) {
      local_2c.z = sqrtf(__x);
    }
    if (local_2c.z == 0.0) {
      local_2c.x = 0.0;
      local_2c.y = 0.0;
      local_2c.z = 1.0;
    }
    else {
      local_2c.z = 1.0 / local_2c.z;
      local_2c.x = fVar3 * local_2c.z;
      local_2c.y = fVar4 * local_2c.z;
      local_2c.z = local_2c.z * fVar2;
    }
    UTIL_VecToAngles(&local_18,&local_2c);
    (peVar1->v_angle).x = local_18.x;
    (peVar1->v_angle).y = local_18.y;
    (peVar1->v_angle).z = local_18.z;
    peVar1 = (this->super_CPointEntity).super_CBaseEntity.pev;
    (peVar1->v_angle).x = -(peVar1->v_angle).x;
  }
  return;
}


// info_intermission  @ 0010b020  (line 6500)

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
  *puVar1 = &PTR__CInfoIntermission_00189a68;
  puVar1[1] = pev;
  return;
}


// CBasePlayer::PositionAvailable  @ 0010d030  (line 6509)

/* DWARF original prototype: BOOL PositionAvailable(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::PositionAvailable(CBasePlayer *this)

{
  BOOL BVar1;
  uint uVar2;
  
  uVar2 = 1;
  BVar1 = CantChange(this,1,0);
  if (BVar1 != 0) {
    BVar1 = CantChange(this,2,0);
    if (BVar1 != 0) {
      BVar1 = CantChange(this,3,0);
      if (BVar1 != 0) {
        BVar1 = CantChange(this,4,0);
        if (BVar1 != 0) {
          BVar1 = CantChange(this,5,0);
          if (BVar1 != 0) {
            BVar1 = CantChange(this,6,0);
            if (BVar1 != 0) {
              BVar1 = CantChange(this,7,0);
              if (BVar1 != 0) {
                BVar1 = CantChange(this,8,0);
                if (BVar1 != 0) {
                  BVar1 = CantChange(this,9,0);
                  uVar2 = (uint)(BVar1 == 0);
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}


// CBasePlayer::CantChange  @ 0010ce90  (line 6517)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL CantChange(CBasePlayer * this, int iClassNo, BOOL showMessage) */

BOOL __thiscall CBasePlayer::CantChange(CBasePlayer *this,int iClassNo,BOOL showMessage)

{
  uint uVar1;
  BOOL BVar2;
  BOOL local_10;
  
                    /* Unresolved local var: int bit@[???] */
  if ((spy_off != 1.0) || (iClassNo != 8)) {
    uVar1 = 1;
    if ((((iClassNo != 1) &&
         (((uVar1 = 2, iClassNo != 2 && (uVar1 = 4, iClassNo != 3)) && (uVar1 = 8, iClassNo != 4))))
        && (((uVar1 = 0x10, iClassNo != 5 && (uVar1 = 0x20, iClassNo != 6)) &&
            (uVar1 = 0x40, iClassNo != 7)))) &&
       (((uVar1 = 0x100, iClassNo != 8 && (uVar1 = 0x200, iClassNo != 9)) && (iClassNo == 10)))) {
      uVar1 = 0x80;
    }
    if ((((illegalclasses[0] & uVar1) == 0) &&
        ((illegalclasses
          [(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no] & uVar1) == 0)) || (iClassNo == 0xb)) {
      BVar2 = ClassIsRestricted((float)(this->super_CBaseMonster).super_CBaseToggle.
                                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                       team_no,iClassNo);
      local_10 = 0;
      if ((BVar2 != 0) && (local_10 = 1, showMessage != 0)) {
        local_10 = 1;
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Game_enoughofclass",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
      }
      return local_10;
    }
  }
  if (showMessage != 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_cantplayclass",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  TeamFortress_DisplayLegalClasses(this);
  return 1;
}


// CBasePlayer::TeamFortress_PrintClassName  @ 0010b090  (line 6548)

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


// CBasePlayer::ChangeClass  @ 0010e860  (line 6557)

/* DWARF original prototype: void ChangeClass(CBasePlayer * this, int iClassNo) */

void __thiscall CBasePlayer::ChangeClass(CBasePlayer *this,int iClassNo)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  globalvars_t *pgVar4;
  _func_void_int *p_Var5;
  _func_char_ptr_char_ptr_char_ptr *p_Var6;
  char *pcVar7;
  long lVar8;
  BOOL BVar9;
  char *pcVar10;
  int iVar11;
  entvars_t *peVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  ushort in_FPUControlWord;
  longdouble extraout_ST0;
  Vector local_50;
  Vector local_44;
  Vector local_38;
  Vector local_2c;
  ushort local_1e;
  
  p_Var6 = g_engfuncs.pfnInfoKeyValue;
                    /* Unresolved local var: int autoKill@[???] */
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  iVar11 = peVar12->playerclass;
  if (iVar11 == iClassNo) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.nextpc == 0) {
      return;
    }
    pcVar7 = UTIL_VarArgs("#%s",sClassNames[iVar11]);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_changeclass",pcVar7,(char *)0x0,(char *)0x0,
                (char *)0x0);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.nextpc = 0;
    return;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.nextpc == iClassNo) {
    return;
  }
  if ((iVar11 != 0) && (gpGlobals->time < this->m_fNextTeamOrClassChange)) {
    return;
  }
  pcVar7 = (*g_engfuncs.pfnGetInfoKeyBuffer)(peVar12->pContainingEntity);
  pcVar7 = (*p_Var6)(pcVar7,"hud_classautokill");
  lVar8 = strtol(pcVar7,(char **)0x0,10);
  BVar9 = PositionAvailable(this);
  if (BVar9 == 0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_enoughofclass",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    Menu_Class(this);
    return;
  }
  BVar9 = TeamFortress_TeamIsCivilian
                    ((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.team_no);
  if ((BVar9 != 0) && (iClassNo != 0xb)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_nochangeclass",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    return;
  }
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  if (peVar12->playerclass != 0) {
    BVar9 = CantChange(this,iClassNo,1);
    if (BVar9 != 0) {
      return;
    }
    pcVar7 = UTIL_VarArgs("#%s",sClassNames[iClassNo]);
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Game_changeclass",pcVar7,(char *)0x0,(char *)0x0,
                (char *)0x0);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.nextpc = iClassNo;
    if ((lVar8 != 0) &&
       (peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev, peVar12->deadflag == 0)) {
      ClientKill(peVar12->pContainingEntity);
    }
    iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
    pcVar7 = sClassNames[iClassNo];
    pcVar14 = "SPECTATOR";
    if (iVar11 != 0) {
      pcVar14 = GetTeamName(iVar11);
    }
    pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                        (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" changed role to \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar10,pcVar14,pcVar7);
    fVar2 = gpGlobals->time;
    this->m_nFirstSpawn = 1;
    this->m_pszLastItem = (char *)0x0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.immune_to_check = fVar2 + 10.0;
    ResetMenu(this);
    this->m_fNextTeamOrClassChange = gpGlobals->time + 1.0;
    return;
  }
  if ((gpGlobals->teamplay != 0.0) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no == 0)) {
    if ((gpGlobals->time <= 30.0) || (tfc_autoteam.value == 0.0)) {
      ClientPrint(peVar12,1,"#Game_mustteam",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      return;
    }
    BVar9 = TeamFortress_TeamPutPlayerInTeam(this);
    if (BVar9 == 0) {
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
  BVar9 = CantChange(this,iClassNo,1);
  if (BVar9 == 0) {
    if (iClassNo == 10) {
      peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      uVar15 = 0xfe00;
      do {
                    /* Unresolved local var: ushort classes@[???] */
        (*g_engfuncs.pfnRandomFloat)(0.0,9.0);
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
        local_1e = in_FPUControlWord & 0xf3ff | 0x400;
        peVar12->playerclass = (int)((double)ROUND(extraout_ST0) + 1.0);
        peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        iVar11 = peVar12->playerclass;
                    /* Unresolved local var: int bit@[???] */
        if ((iVar11 != 8) || (spy_off != 1.0)) {
          uVar13 = 1;
          if ((((iVar11 != 1) &&
               (((uVar13 = 2, iVar11 != 2 && (uVar13 = 4, iVar11 != 3)) && (uVar13 = 8, iVar11 != 4)
                ))) && ((((uVar13 = 0x10, iVar11 != 5 && (uVar13 = 0x20, iVar11 != 6)) &&
                         (uVar13 = 0x40, iVar11 != 7)) &&
                        ((uVar13 = 0x100, iVar11 != 8 && (uVar13 = 0x200, iVar11 != 9)))))) &&
             (uVar13 = 0, iVar11 == 10)) {
            uVar13 = 0x80;
          }
          if (((illegalclasses[0] & uVar13) == 0) &&
             (iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.team_no,
             (illegalclasses[iVar3] & uVar13) == 0)) {
            BVar9 = ClassIsRestricted((float)iVar3,iVar11);
            peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev;
            if (BVar9 == 0) break;
          }
        }
        uVar15 = 1 << ((char)iVar11 - 1U & 0x1f) & 0xffffU | uVar15;
      } while (uVar15 != 0xffff);
      BVar9 = CantChange(this,peVar12->playerclass,0);
      if (BVar9 != 0) {
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Game_enoughofclass",(char *)0x0,
                    (char *)0x0,(char *)0x0,(char *)0x0);
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->playerclass = 0;
        goto LAB_0010f280;
      }
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Game_random",(char *)0x0,(char *)0x0,(char *)0x0,
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
      peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      this->m_SbarString2[0] = '\n';
      this->m_SbarString1[0] = '\n';
      this->m_SbarString0[0] = '\n';
      peVar12->playerclass = iClassNo;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.nextpc = 0;
    }
    iVar11 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no;
    pcVar7 = sClassNames[iClassNo];
    pcVar14 = "SPECTATOR";
    if (iVar11 != 0) {
      pcVar14 = GetTeamName(iVar11);
    }
    pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)
                        (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar11 = (*g_engfuncs.pfnGetPlayerUserId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" changed role to \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar11,pcVar10,pcVar14,pcVar7);
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if ((peVar12->iuser1 != 0) || (peVar12->iuser2 != 0)) {
      (*g_engfuncs.pfnMessageBegin)(2,gmsgSpectator,(float *)0x0,(edict_t *)0x0);
      p_Var5 = g_engfuncs.pfnWriteByte;
      iVar11 = (*g_engfuncs.pfnIndexOfEdict)
                         (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      (*p_Var5)(iVar11);
      (*g_engfuncs.pfnWriteByte)(0);
      (*g_engfuncs.pfnMessageEnd)();
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgResetFade,(float *)0x0,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity);
      (*g_engfuncs.pfnMessageEnd)();
      peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev;
      peVar12->iuser2 = 0;
      peVar12->iuser1 = 0;
    }
    this->m_fNextTeamOrClassChange = gpGlobals->time + 1.0;
    EHANDLE::operator=(&this->m_hObserverTarget,(CBaseEntity *)0x0);
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->weapons;
    *piVar1 = *piVar1 | 0x80000000;
    this->m_iHideHUD = 0;
    TeamFortress_SetEquipment(this);
    TeamFortress_SetHealth(this);
    TeamFortress_SetSpeed(this);
    TeamFortress_SetSkin(this);
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->takedamage = 2.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->solid = 3;
    pgVar4 = gpGlobals;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->movetype = 3;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->flags = 0x208;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->waterlevel = 0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->air_finished = pgVar4->time + 12.0;
    piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->effects;
    *piVar1 = *piVar1 & 0xffffff7f;
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    (peVar12->view_ofs).x = 0.0;
    (peVar12->view_ofs).y = 0.0;
    (peVar12->view_ofs).z = 28.0;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->deadflag = 0;
    this->m_flFallVelocity = 0.0;
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    iVar11 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
    peVar12->sequence = iVar11;
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if ((peVar12->flags & 0x4000) == 0) {
      local_2c.x = 16.0;
      local_2c.y = 16.0;
      local_2c.z = 36.0;
      local_38.x = -16.0;
      local_38.y = -16.0;
      local_38.z = -36.0;
      UTIL_SetSize(peVar12,&local_38,&local_2c);
    }
    else {
      local_44.x = 16.0;
      local_44.y = 16.0;
      local_44.z = 18.0;
      local_50.x = -16.0;
      local_50.y = -16.0;
      local_50.z = -18.0;
      UTIL_SetSize(peVar12,&local_50,&local_44);
    }
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    iVar11 = peVar12->playerclass;
    if ((((iVar11 != 10) && (iVar11 != 0)) &&
        (iVar11 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.lastpc)) &&
       (iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.exec_scripts,
       (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.lastpc = iVar11, iVar3 != 0)) {
      (*g_engfuncs.pfnMessageBegin)(1,0x3b,(float *)0x0,peVar12->pContainingEntity);
      (*g_engfuncs.pfnWriteByte)(1);
      (*g_engfuncs.pfnWriteByte)
                (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->playerclass);
      (*g_engfuncs.pfnMessageEnd)();
    }
    (*g_pGameRules->_vptr_CGameRules[0x16])(g_pGameRules,this);
  }
  else {
LAB_0010f280:
    Menu_Class(this);
  }
  return;
}


// CBasePlayer::SetLastWeapon  @ 0010b0f0  (line 6791)

/* DWARF original prototype: void SetLastWeapon(CBasePlayer * this) */

void __thiscall CBasePlayer::SetLastWeapon(CBasePlayer *this)

{
  char *__s2;
  CBasePlayerItem *pCVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???] */
  this->m_pLastItem = (CBasePlayerItem *)0x0;
  if ((this->m_nFirstSpawn != 0) || (__s2 = this->m_pszLastItem, __s2 == (char *)0x0)) {
    return;
  }
  iVar3 = 0;
  do {
                    /* Unresolved local var: int i@[???] */
    for (pCVar1 = this->m_rgpPlayerItems[iVar3]; pCVar1 != (CBasePlayerItem *)0x0;
        pCVar1 = pCVar1->m_pNext) {
                    /* Unresolved local var: ItemInfo * Info@[???] */
      if ((CBasePlayerItem::ItemInfoArray[pCVar1->m_iId].pszName != (char *)0x0) &&
         (iVar2 = strcmp(CBasePlayerItem::ItemInfoArray[pCVar1->m_iId].pszName,__s2), iVar2 == 0)) {
        this->m_pLastItem = pCVar1;
        return;
      }
    }
    iVar3 = iVar3 + 1;
    if (iVar3 == 6) {
      return;
    }
  } while( true );
}


// CBasePlayer::TeamFortress_SetEquipment  @ 0010b180  (line 6824)

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
  int local_20;
  
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
    super_CBaseEntity.weapons_carried = (int)"veDataE";
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
    super_CBaseEntity.items_allowed = (int)"veDataE";
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
    super_CBaseEntity.ammo_nails = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = 0;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
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
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 | 2;
    piVar1 = &peVar7->effects;
    *piVar1 = *piVar1 | 0x80;
    peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
                    /* Unresolved local var: CBasePlayerItem * pCheck@[???] */
  this->m_pLastItem = (CBasePlayerItem *)0x0;
  if ((this->m_nFirstSpawn == 0) && (__s2 = this->m_pszLastItem, __s2 != (char *)0x0)) {
    local_20 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      for (pCVar4 = this->m_rgpPlayerItems[local_20]; pCVar4 != (CBasePlayerItem *)0x0;
          pCVar4 = pCVar4->m_pNext) {
                    /* Unresolved local var: ItemInfo * Info@[???] */
        if ((CBasePlayerItem::ItemInfoArray[pCVar4->m_iId].pszName != (char *)0x0) &&
           (iVar5 = strcmp(CBasePlayerItem::ItemInfoArray[pCVar4->m_iId].pszName,__s2), iVar5 == 0))
        {
          this->m_pLastItem = pCVar4;
          goto LAB_0010b56d;
        }
      }
      local_20 = local_20 + 1;
    } while (local_20 != 6);
  }
LAB_0010b56d:
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


// CBasePlayer::TeamFortress_SetHealth  @ 0010c0a0  (line 7329)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetHealth(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetHealth(CBasePlayer *this)

{
  int iVar1;
  entvars_t *peVar2;
  
                    /* Unresolved local var: int playerclass@[???] */
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar1 = peVar2->playerclass;
  if (iVar1 == 1) {
    peVar2->max_health = 75.0;
    peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar2->health = peVar2->max_health;
    return;
  }
  if (iVar1 != 2) {
    if (iVar1 == 3) {
LAB_0010c130:
      peVar2->max_health = 100.0;
      peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      peVar2->health = peVar2->max_health;
      return;
    }
    if ((iVar1 != 4) && (iVar1 != 5)) {
      if ((iVar1 == 6) || (iVar1 == 7)) goto LAB_0010c130;
      if (iVar1 == 0xb) {
        peVar2->max_health = 50.0;
        peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        goto LAB_0010c11d;
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
        goto LAB_0010c11d;
      }
    }
  }
  peVar2->max_health = 90.0;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
LAB_0010c11d:
  peVar2->health = peVar2->max_health;
  return;
}


// CBasePlayer::TeamFortress_SetSpeed  @ 0010c190  (line 7364)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetSpeed(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetSpeed(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  uint uVar3;
  CBaseEntity *pStartEntity;
  float fVar4;
  float local_14;
  
                    /* Unresolved local var: int playerclass@[???]
                       Unresolved local var: float maxfbspeed@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar2 = peVar1->playerclass;
  if (peVar1->iuser1 != 0) {
    fVar4 = 400.0;
    if (peVar1->iuser1 != 3) {
      fVar4 = 0.0;
    }
    peVar1->maxspeed = fVar4;
    return;
  }
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate & 0x10000) == 0) && (iVar2 != 0)) {
    local_14 = 400.0;
    if ((((iVar2 != 1) &&
         ((((local_14 = 300.0, iVar2 != 2 && (local_14 = 240.0, iVar2 != 3)) &&
           (local_14 = 280.0, iVar2 != 4)) &&
          ((local_14 = 320.0, iVar2 != 5 && (local_14 = 230.0, iVar2 != 6)))))) &&
        (local_14 = 300.0, iVar2 != 7)) && (local_14 = 240.0, iVar2 != 0xb)) {
      local_14 = 300.0;
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
    uVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.tfstate;
    if ((uVar3 & 0x8000) != 0) {
      local_14 = local_14 * 0.5;
    }
    fVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.leg_damage;
    if (fVar4 != 0.0) {
      if (6.0 < fVar4) {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.leg_damage = 6.0;
        fVar4 = 0.4;
      }
      else {
        fVar4 = (10.0 - fVar4) / 10.0;
      }
      local_14 = fVar4 * local_14;
    }
    if (((uVar3 & 0x800) != 0) && (80.0 < local_14)) {
      local_14 = 80.0;
    }
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->maxspeed = local_14;
    return;
  }
  (peVar1->velocity).x = g_vecZero.x;
  (peVar1->velocity).y = g_vecZero.y;
  (peVar1->velocity).z = g_vecZero.z;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->maxspeed = 1.0;
  return;
}


// CBasePlayer::TeamFortress_SetSkin  @ 0010c7b0  (line 7478)

/* DWARF original prototype: void TeamFortress_SetSkin(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetSkin(CBasePlayer *this)

{
  int *piVar1;
  entvars_t *peVar2;
  string_t sVar3;
  edict_t *peVar4;
  globalvars_t *pgVar5;
  _func_void_int_char_ptr_char_ptr_char_ptr *p_Var6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  _func_void_int_char_ptr_char_ptr_char_ptr *local_50;
  Vector local_4c;
  Vector local_40;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: char * infobuffer@[???]
                       Unresolved local var: int iClassToUse@[???]
                       Unresolved local var: int iTeamToUse@[???] */
  pcVar7 = (*g_engfuncs.pfnGetInfoKeyBuffer)
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pgVar5 = gpGlobals;
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
      goto LAB_0010c872;
    }
    (*g_engfuncs.pfnSetModel)(peVar4,"models/player/scout/scout.mdl");
    pcVar9 = sClassModels[iVar10];
    local_50 = g_engfuncs.pfnSetClientKeyValue;
  }
  else {
    local_50 = g_engfuncs.pfnSetClientKeyValue;
    pcVar9 = UTIL_VarArgs("%s",pgVar5->pStringBase + sVar3);
  }
  iVar8 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*local_50)(iVar8,pcVar7,"model",pcVar9);
LAB_0010c872:
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
  if ((peVar2->flags & 0x4000) == 0) {
    local_28[0].x = 16.0;
    local_28[0].y = 16.0;
    local_28[0].z = 36.0;
    local_34.x = -16.0;
    local_34.y = -16.0;
    local_34.z = -36.0;
    UTIL_SetSize(peVar2,&local_34,local_28);
  }
  else {
    local_40.x = 16.0;
    local_40.y = 16.0;
    local_40.z = 18.0;
    local_4c.x = -16.0;
    local_4c.y = -16.0;
    local_4c.z = -18.0;
    UTIL_SetSize(peVar2,&local_4c,&local_40);
  }
  g_ulModelIndexPlayer =
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->modelindex;
  return;
}


// CBasePlayer::IsLegalClass  @ 0010ca50  (line 7526)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL IsLegalClass(CBasePlayer * this, int pc) */

BOOL __thiscall CBasePlayer::IsLegalClass(CBasePlayer *this,int pc)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int bit@[???] */
  if ((pc == 8) && (spy_off == 1.0)) {
    return 0;
  }
  uVar2 = 1;
  if ((((((pc != 1) && (uVar2 = 2, pc != 2)) && (uVar2 = 4, pc != 3)) &&
       ((uVar2 = 8, pc != 4 && (uVar2 = 0x10, pc != 5)))) &&
      ((uVar2 = 0x20, pc != 6 && ((uVar2 = 0x40, pc != 7 && (uVar2 = 0x100, pc != 8)))))) &&
     ((uVar2 = 0x200, pc != 9 && (pc == 10)))) {
    uVar2 = 0x80;
  }
  uVar1 = 0;
  if ((illegalclasses[0] & uVar2) == 0) {
    uVar1 = (uint)((illegalclasses
                    [(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.team_no] & uVar2) == 0);
  }
  return uVar1;
}


// CBasePlayer::TeamFortress_DisplayLegalClasses  @ 0010cb20  (line 7563)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_DisplayLegalClasses(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_DisplayLegalClasses(CBasePlayer *this)

{
  uint uVar1;
  
                    /* Unresolved local var: int gotone@[???]
                       Unresolved local var: int ill@[???] */
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Game_legalclasses",(char *)0x0,(char *)0x0,(char *)0x0,
              (char *)0x0);
  uVar1 = illegalclasses
          [(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.team_no];
  if (((illegalclasses[0] & 1U) == 0) && ((uVar1 & 1) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Scout",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  if (((illegalclasses[0] & 2U) == 0) && ((uVar1 & 2) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Sniper",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  if (((illegalclasses[0] & 4U) == 0) && ((uVar1 & 4) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Soldier",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  if (((illegalclasses[0] & 8U) == 0) && ((uVar1 & 8) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Demoman",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  if (((illegalclasses[0] & 0x10U) == 0) && ((uVar1 & 0x10) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Medic",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  if (((illegalclasses[0] & 0x20U) == 0) && ((uVar1 & 0x20) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#HWGuy",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  if (((illegalclasses[0] & 0x40U) == 0) && ((uVar1 & 0x40) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Pyro",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  if (((illegalclasses[0] & 0x100U) == 0) && ((uVar1 & 0x100) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Spy",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  }
  if (((illegalclasses[0] & 0x200U) == 0) && ((uVar1 & 0x200) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Engineer",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0)
    ;
  }
  if (((illegalclasses[0] & 0x80U) == 0) && ((uVar1 & 0x80) == 0)) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#RandomPC",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0)
    ;
    return;
  }
  return;
}


// CBasePlayer::TeamFortress_ExecClassScript  @ 0010d160  (line 7616)

/* DWARF original prototype: void TeamFortress_ExecClassScript(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_ExecClassScript(CBasePlayer *this)

{
  entvars_t *peVar1;
  int iVar2;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar2 = peVar1->playerclass;
  if ((((iVar2 != 10) && (iVar2 != 0)) &&
      (iVar2 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.lastpc)) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.lastpc = iVar2,
     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.exec_scripts != 0)) {
    (*g_engfuncs.pfnMessageBegin)(1,0x3b,(float *)0x0,peVar1->pContainingEntity);
    (*g_engfuncs.pfnWriteByte)(1);
    (*g_engfuncs.pfnWriteByte)
              (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev)->playerclass);
                    /* WARNING: Could not recover jumptable at 0x0010d1e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  return;
}


// CBasePlayer::TeamFortress_ExecMapScript  @ 0010d1f0  (line 7638)

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
                    /* WARNING: Could not recover jumptable at 0x0010d246. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::TeamFortress_TeamPutPlayerInTeam  @ 0010e740  (line 7653)

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
  float local_30;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int lowest@[???]
                       Unresolved local var: float likely_team@[???] */
  lVar5 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,number_of_teams);
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  local_30 = (float)ROUND(lVar5);
  if (local_30 == 0.0) {
    local_30 = number_of_teams;
  }
  fVar1 = 1.0;
  if (1.0 < number_of_teams + 1.0) {
    iVar4 = 0x21;
    tno = 1;
    do {
      iVar2 = TeamFortress_TeamGetNoPlayers(tno);
      iVar2 = iVar2 - (uint)(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->team == tno);
      if (iVar2 < iVar4) {
        if (iVar2 < teammaxplayers[tno]) {
          local_30 = fVar1;
        }
        if (iVar2 < teammaxplayers[tno]) {
          iVar4 = iVar2;
        }
      }
      tno = tno + 1;
      fVar1 = (float)tno;
    } while (fVar1 < number_of_teams + 1.0);
  }
  BVar3 = TeamFortress_TeamSet(this,(int)local_30);
  return BVar3;
}


// CBasePlayer::TeamFortress_TeamSet  @ 0010e0b0  (line 7690)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL TeamFortress_TeamSet(CBasePlayer * this, int tno) */

BOOL __thiscall CBasePlayer::TeamFortress_TeamSet(CBasePlayer *this,int tno)

{
  int *piVar1;
  uint uVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  _func_void_int *p_Var5;
  _func_void_char_ptr *p_Var6;
  int iVar7;
  char *pcVar8;
  CBaseEntity *pCVar9;
  CBasePlayer *pCVar10;
  int iVar11;
  edict_t *peVar12;
  void *pvVar13;
  CBasePlayer *pCVar14;
  CBasePlayer *pStartEntity;
  char *pcVar15;
  char *pcVar16;
  
                    /* Unresolved local var: int tc@[???] */
  iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if ((0 < iVar7) && (iVar7 == tno)) {
    return 0;
  }
  if (gpGlobals->teamplay == 0.0) {
    pcVar16 = (char *)0x0;
    pcVar15 = "#Game_noteams";
LAB_0010e188:
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,pcVar15,pcVar16,(char *)0x0,(char *)0x0,(char *)0x0);
    return 0;
  }
  if ((number_of_teams < (float)tno) && (number_of_teams != 0.0)) {
    pcVar16 = UTIL_dtos1((int)number_of_teams);
    pcVar15 = "Game_onlyteams";
    goto LAB_0010e188;
  }
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->deadflag == 1) {
    return 0;
  }
  if (gpGlobals->time < this->m_fNextTeamOrClassChange) {
    return 0;
  }
  iVar7 = TeamFortress_TeamGetNoPlayers(tno);
  if (teammaxplayers[tno] <= iVar7) {
    if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no == 0) {
      Menu_Team(this);
    }
    pcVar16 = (char *)0x0;
    pcVar15 = "#Game_teamfull";
    goto LAB_0010e188;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no < 1) {
    pcVar16 = UTIL_dtos1(tno);
    pcVar15 = "SPECTATOR";
    UTIL_ClientPrintAll(1,"#Game_joinedteam",
                        gpGlobals->pStringBase +
                        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->netname,pcVar16,(char *)0x0,
                        (char *)0x0);
    if (tno != 0) {
      pcVar15 = GetTeamName(tno);
    }
    iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    pcVar16 = "SPECTATOR";
    if (iVar7 != 0) {
      pcVar16 = GetTeamName(iVar7);
    }
    pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar7 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" joined team \"%s\"\n",
                   gpGlobals->pStringBase +
                   ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar7,pcVar8,pcVar16,pcVar15);
    goto LAB_0010e475;
  }
  pcVar16 = UTIL_dtos1(tno);
  pcVar15 = "SPECTATOR";
  UTIL_ClientPrintAll(1,"#Game_changedteam",
                      gpGlobals->pStringBase +
                      ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->netname,pcVar16,(char *)0x0,
                      (char *)0x0);
  if (tno != 0) {
    pcVar15 = GetTeamName(tno);
  }
  iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  pcVar16 = "SPECTATOR";
  if (iVar7 != 0) {
    pcVar16 = GetTeamName(iVar7);
  }
  pcVar8 = (*g_engfuncs.pfnGetPlayerAuthId)
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar7 = (*g_engfuncs.pfnGetPlayerUserId)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" joined team \"%s\"\n",
                 gpGlobals->pStringBase +
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->netname,iVar7,pcVar8,pcVar16,pcVar15);
  uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
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
  for (pCVar9 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_rpg_rocket");
      pCVar9 != (CBaseEntity *)0x0; pCVar9 = UTIL_FindEntityByClassname(pCVar9,"tf_rpg_rocket")) {
    if (pCVar9->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &pCVar9->pev->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pcVar16 = "tf_ic_rocket";
  pCVar14 = (CBasePlayer *)0x0;
  pCVar10 = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)0x0,"tf_ic_rocket");
  while (pStartEntity = pCVar10, pStartEntity != (CBasePlayer *)0x0) {
    peVar3 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar3->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      piVar1 = &peVar3->flags;
      *piVar1 = *piVar1 | 0x40000000;
    }
    pcVar16 = "tf_ic_rocket";
    pCVar10 = (CBasePlayer *)UTIL_FindEntityByClassname((CBaseEntity *)pStartEntity,"tf_ic_rocket");
    pCVar14 = pStartEntity;
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->playerclass = 0;
  piVar1 = &(this->super_CBaseMonster).m_bitsDamageType;
  *piVar1 = *piVar1 & 0xff003fff;
  this->m_fInitHUD = 1;
  iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  this->m_fWeapon = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.nextpc = 0;
  if ((iVar7 & 0x10) != 0) {
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    pcVar16 = (char *)0x2;
    pCVar14 = this;
    pCVar9 = CBaseEntity::FindTimer((CBaseEntity *)this,2);
    if (pCVar9 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
      peVar12 = pCVar9->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if (peVar12 == (edict_t *)0x0) {
        pCVar14 = (CBasePlayer *)0x0;
        peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        if (peVar12 != (edict_t *)0x0) goto LAB_0010e5fa;
        pvVar13 = (void *)0x0;
      }
      else {
LAB_0010e5fa:
        pvVar13 = peVar12->pvPrivateData;
      }
      iVar7 = *(int *)((int)pvVar13 + 0x144) + 1;
      *(int *)((int)pvVar13 + 0x144) = iVar7;
      if (*(int *)((int)pvVar13 + 0x138) != 0) {
        teamfrags[*(int *)((int)pvVar13 + 0x138)] = teamfrags[*(int *)((int)pvVar13 + 0x138)] + 1;
      }
      *(float *)(*(int *)((int)pvVar13 + 4) + 0x164) = (float)iVar7;
    }
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.tfstate = 0;
  RemoveAllItems(pCVar14,(BOOL)pcVar16);
  this->m_fDontPackItemsUntil = gpGlobals->time + 0.2;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->health = 0.0;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0xf])
            (this,0,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1);
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.real_frags + 1;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.real_frags = iVar7;
  peVar3->frags = (float)iVar7;
  this->m_iDeaths = this->m_iDeaths + -1;
LAB_0010e475:
  this->m_nFirstSpawn = 1;
  this->m_pszLastItem = (char *)0x0;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = tno;
  peVar3->team = tno;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.lives = teamlives[tno];
  pgVar4 = gpGlobals;
  this->m_fNextTeamOrClassChange = gpGlobals->time + 1.0;
                    /* Unresolved local var: int i@[???] */
  if (0 < pgVar4->maxClients) {
    iVar7 = 1;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pCVar14 = UTIL_PlayerByIndex(iVar7);
      if (pCVar14 != (CBasePlayer *)0x0) {
        (*g_engfuncs.pfnMessageBegin)
                  (1,gmsgTeamInfo,(float *)0x0,
                   ((pCVar14->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        p_Var5 = g_engfuncs.pfnWriteByte;
        iVar11 = (*g_engfuncs.pfnIndexOfEdict)
                           (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                             super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
        (*p_Var5)(iVar11);
        p_Var6 = g_engfuncs.pfnWriteString;
        pcVar16 = (char *)(*g_pGameRules->_vptr_CGameRules[0x31])(g_pGameRules,this);
        (*p_Var6)(pcVar16);
        (*g_engfuncs.pfnMessageEnd)();
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 <= gpGlobals->maxClients);
  }
  TeamFortress_TeamIncreaseScore
            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no,0);
  TeamFortress_SetSkin(this);
  Menu_Class(this);
  return 1;
}


// CBasePlayer::TeamFortress_TeamShowMemberClasses  @ 0010d250  (line 7841)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TeamShowMemberClasses(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_TeamShowMemberClasses(CBasePlayer *this)

{
  bool bVar1;
  CBasePlayer *pOther;
  BOOL BVar2;
  char *param2;
  int playerIndex;
  
                    /* Unresolved local var: int found@[???]
                       Unresolved local var: int i@[???] */
  if (0 < gpGlobals->maxClients) {
    playerIndex = 1;
    bVar1 = false;
    do {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      pOther = UTIL_PlayerByIndex(playerIndex);
      if ((pOther != (CBasePlayer *)0x0) && (this != pOther)) {
        BVar2 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther);
        if (BVar2 != 0) {
          if (!bVar1) {
            ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,"#Game_others",(char *)0x0,
                        (char *)0x0,(char *)0x0,(char *)0x0);
          }
          param2 = UTIL_VarArgs("#%s",sClassNames
                                      [((pOther->super_CBaseMonster).super_CBaseToggle.
                                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                                       ->playerclass]);
          bVar1 = true;
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Game_othersdetails",
                      gpGlobals->pStringBase +
                      ((pOther->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->netname,param2,(char *)0x0,
                      (char *)0x0);
        }
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


// CBasePlayer::Engineer_RemoveBuildings  @ 0010d3c0  (line 7872)

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
    pCVar3 = EHANDLE::operator_CBaseEntity_(this_00);
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


// CBasePlayer::TeamFortress_RemoveLiveGrenades  @ 0010df40  (line 7904)

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


// CBasePlayer::TeamFortress_RemoveRockets  @ 0010f8e0  (line 7916)

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


// CBasePlayer::RemoveOwnedEnt  @ 0010f9a0  (line 7924)

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


// CBasePlayer::Ignite  @ 0010fa20  (line 7939)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Ignite(CBasePlayer * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker) */

void __thiscall
CBasePlayer::Ignite(CBasePlayer *this,entvars_t *pevInflictor,entvars_t *pevAttacker)

{
  int *piVar1;
  CTFFlame *pCVar2;
  BOOL BVar3;
  edict_t *peVar4;
  CBaseEntity *pOther;
  
                    /* Unresolved local var: CBaseEntity * pAttacker@[DW_OP_reg6(ESI)] */
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0xd])(this,pevInflictor,pevAttacker,0x40c00000,8);
  if (cb_prematch_time <= gpGlobals->time) {
    if (4.0 <= (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.numflames) {
      piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar1 = *piVar1 | 0x20000;
      return;
    }
    if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armorclass & 0x10) == 0) ||
       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->armorvalue <= 0.0)) {
      peVar4 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar4 == (edict_t *)0x0) &&
         (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
        pOther = (CBaseEntity *)0x0;
      }
      else {
        pOther = peVar4->pvPrivateData;
      }
      if ((((int)gpGlobals->teamplay & 0x10U) == 0) ||
         (BVar3 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther), BVar3 == 0)) {
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.numflames =
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.numflames + 1.0;
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,4,"#Pyro_onfire",(char *)0x0,(char *)0x0,
                    (char *)0x0,(char *)0x0);
        EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,2,
                       "ambience/flameburst1.wav",1.0,0.8,0,100);
        if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.numflames == 1.0) {
                    /* Unresolved local var: CTFFlame * pFlame@[???] */
          pCVar2 = CTFFlame::FlameSpawn(pOther,(CBaseEntity *)this);
          piVar1 = &((pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->effects;
          *piVar1 = *piVar1 & 0xffffff7f;
        }
      }
    }
  }
  return;
}


// CBasePlayer::TF_AddFrags  @ 00110700  (line 7977)

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


// CBasePlayer::TeamFortress_RemoveTimers  @ 00110740  (line 7995)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_RemoveTimers(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_RemoveTimers(CBasePlayer *this)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  uint uVar2;
  CBaseEntity *pCVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
                    /* Unresolved local var: CBaseEntity * pTimer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.leg_damage = 0.0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_undercover = 0;
  if ((uVar2 & 0x800) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar2 & 0xfffff7ff;
    TeamFortress_SetSpeed(this);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.heat = 0.0;
  }
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.building;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.is_building != 0) && (iVar5 = EHANDLE::operator_int(this_00), iVar5 != 0))
  {
    pCVar3 = EHANDLE::operator_CBaseEntity_(this_00);
    UTIL_Remove(pCVar3);
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.is_building = 0;
  EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  if ((uVar2 & 0x10) != 0) {
    uVar2 = uVar2 & 0xffffffef;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar2;
  }
  if ((uVar2 & 0x4000) != 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar2 & 0xffffbfff;
  }
  while (pCVar3 = CBaseEntity::FindTimer((CBaseEntity *)this,0), pCVar3 != (CBaseEntity *)0x0) {
    if (pCVar3->no_active_gas_grens <= 0.0) {
      CBaseEntity::SUB_Remove(pCVar3);
    }
  }
  for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"item_tfgoal");
      pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"item_tfgoal")) {
    if (pCVar3->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) {
      if ((pCVar3->goal_activation & 0x100) == 0) {
        tfgoalitem_RemoveFromPlayer(pCVar3,this,0);
      }
      if (CTF_Map == 1) {
        if (pCVar3->goal_no == 1) {
          pcVar4 = UTIL_VarArgs("%s LOST the BLUE flag!\n",
                                gpGlobals->pStringBase +
                                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev)->netname);
          pcVar6 = "SPECTATOR";
          UTIL_ClientPrintAll(4,pcVar4,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no;
          if (iVar5 != 0) {
            pcVar6 = GetTeamName(iVar5);
          }
          pcVar4 = (*g_engfuncs.pfnGetPlayerAuthId)
                             (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dropped_Blue_Flag\"\n",
                         gpGlobals->pStringBase +
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar5,pcVar4,pcVar6);
        }
        else if (pCVar3->goal_no == 2) {
          pcVar4 = UTIL_VarArgs("%s LOST the RED flag!\n",
                                gpGlobals->pStringBase +
                                ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev)->netname);
          pcVar6 = "SPECTATOR";
          UTIL_ClientPrintAll(4,pcVar4,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
          iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no;
          if (iVar5 != 0) {
            pcVar6 = GetTeamName(iVar5);
          }
          pcVar4 = (*g_engfuncs.pfnGetPlayerAuthId)
                             (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dropped_Red_Flag\"\n",
                         gpGlobals->pStringBase +
                         ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar5,pcVar4,pcVar6);
        }
      }
    }
  }
  for (pCVar3 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"detpack");
      pCVar3 != (CBaseEntity *)0x0; pCVar3 = UTIL_FindEntityByClassname(pCVar3,"detpack")) {
    if ((pCVar3->weaponmode == 1.0) &&
       (pCVar3->pev->enemy ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity)) {
      pCVar3->weaponmode = 0.0;
    }
  }
  ExplodeOldPipebomb(this,1,1);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.item_list = 0;
  ResetMenu(this);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->renderfx = 0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar1->rendercolor).x = g_vecZero.x;
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


// CBasePlayer::TeamFortress_SetupRespawn  @ 00111cb0  (line 8097)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetupRespawn(CBasePlayer * this, BOOL bSuicided) */

void __thiscall CBasePlayer::TeamFortress_SetupRespawn(CBasePlayer *this,BOOL bSuicided)

{
  float fVar1;
  float fVar2;
  globalvars_t *pgVar3;
  CBasePlayer *in_EAX;
  int d;
  char *pcVar4;
  int in_EDX;
  
                    /* Unresolved local var: float flRestime@[???] */
  in_EAX->m_idrownrestored = 0;
  pgVar3 = gpGlobals;
  fVar2 = tfc_respawndelay.value;
  in_EAX->m_idrowndmg = 0;
  (in_EAX->super_CBaseMonster).m_rgbTimeBasedDamage[4] = '\0';
  fVar1 = pgVar3->time;
  if (cb_prematch_time < fVar1 + 1.0) {
    d = (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.lives;
    if (in_EDX != 0) {
      if (0 < d) {
        d = d + -1;
        (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.lives = d;
        fVar1 = pgVar3->time;
      }
      fVar2 = in_EAX->m_fNextSuicideTime - fVar1;
    }
    if (d < 1) {
      if (d == -1) goto LAB_00111d92;
    }
    else {
      d = d + -1;
      (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.lives = d;
    }
    if (d == 0) {
      ClientPrint((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,4,"#Game_nolives",(char *)0x0,(char *)0x0,
                  (char *)0x0,(char *)0x0);
      StartDeathCam(in_EAX);
      return;
    }
    if (d == 1) {
      ClientPrint((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,4,"#Game_lastlife",(char *)0x0,(char *)0x0,
                  (char *)0x0,(char *)0x0);
      fVar1 = gpGlobals->time;
    }
    else {
      pcVar4 = UTIL_dtos1(d);
      ClientPrint((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev,1,"#Game_Xlives",pcVar4,(char *)0x0,
                  (char *)0x0,(char *)0x0);
      fVar1 = gpGlobals->time;
    }
  }
LAB_00111d92:
  (in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.respawn_time = fVar1 + fVar2;
  if (3.0 < fVar2) {
    pcVar4 = UTIL_dtos1((int)fVar2);
    ClientPrint((in_EAX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                .super_CBaseEntity.pev,1,"#Game_tillrespawn",pcVar4,(char *)0x0,(char *)0x0,
                (char *)0x0);
  }
  return;
}


// CBasePlayer::TeamFortress_SetupRespawn  @ 00112390  (line 8098)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetupRespawn(CBasePlayer * this, BOOL bSuicided) */

void __thiscall CBasePlayer::TeamFortress_SetupRespawn(CBasePlayer *this,BOOL bSuicided)

{
                    /* Unresolved local var: float flRestime@[???] */
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.respawn_time <= gpGlobals->time) {
    TeamFortress_SetupRespawn(this,bSuicided);
    return;
  }
  return;
}


// CBasePlayer::TeamFortress_CheckClassStats  @ 001123c0  (line 8155)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_CheckClassStats(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_CheckClassStats(CBasePlayer *this)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  entvars_t *peVar4;
  int iVar5;
  
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.armor_allowed;
  if (fVar1 < peVar4->armortype) {
    peVar4->armortype = fVar1;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  fVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor;
  if (fVar1 < peVar4->armorvalue) {
    peVar4->armorvalue = fVar1;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar4->armortype < 0.0) {
    peVar4->armortype = 0.0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  if (peVar4->armorvalue < 0.0) {
    peVar4->armorvalue = 0.0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_shells;
  if (iVar3 < iVar5) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = iVar3;
    iVar5 = iVar3;
  }
  if (iVar5 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = 0;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_nails;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_nails;
  if (iVar3 < iVar5) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = iVar3;
    iVar5 = iVar3;
  }
  if (iVar5 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_nails = 0;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_rockets;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_rockets;
  if (iVar3 < iVar5) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = iVar3;
    iVar5 = iVar3;
  }
  if (iVar5 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = 0;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_cells;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_cells;
  if (iVar3 < iVar5) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = iVar3;
    iVar5 = iVar3;
  }
  if (iVar5 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = 0;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_medikit;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_medikit;
  if (iVar3 < iVar5) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_medikit = iVar3;
    iVar5 = iVar3;
  }
  if (iVar5 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_medikit = 0;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_detpack;
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_detpack;
  if (iVar3 < iVar5) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_detpack = iVar3;
    iVar5 = iVar3;
  }
  if (iVar5 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_detpack = 0;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1;
  if (iVar5 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 0;
    iVar5 = 0;
  }
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_2;
  if (iVar3 < 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 0;
    iVar3 = 0;
  }
  if (4 < iVar5) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 4;
  }
  if (4 < iVar3) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 4;
  }
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tp_grenades_1;
  if ((iVar5 == 3) &&
     (2 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
  }
  iVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tp_grenades_2;
  if ((iVar3 == 3) &&
     (2 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_2)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 2;
  }
  if ((iVar5 == 4) &&
     (2 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 2;
  }
  if ((iVar3 == 4) &&
     (2 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_2)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 2;
  }
  if ((iVar5 == 2) &&
     (3 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 3;
  }
  if ((iVar3 == 2) &&
     (3 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_2)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 3;
  }
  if ((iVar5 == 9) &&
     (3 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_1)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_1 = 3;
  }
  if ((iVar3 == 9) &&
     (3 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.no_grenades_2)) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.no_grenades_2 = 3;
  }
  fVar1 = peVar4->health;
  if ((peVar4->max_health < fVar1) &&
     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.items & 0x10000) == 0)) {
    peVar4->health = peVar4->max_health;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar1 = peVar4->health;
  }
  if (fVar1 < 0.0) {
    peVar4->health = 0.0;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  uVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.items & 0xffff1fff;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.items = uVar2;
  fVar1 = peVar4->armortype;
  if (0.8 <= fVar1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = uVar2 | 0x8000;
    return;
  }
  if (0.6 <= fVar1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = uVar2 | 0x4000;
    return;
  }
  if (0.3 <= fVar1) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.items = uVar2 | 0x2000;
  }
  return;
}


// CBasePlayer::ForceRespawn  @ 001127e0  (line 8238)

/* DWARF original prototype: void ForceRespawn(CBasePlayer * this) */

void __thiscall CBasePlayer::ForceRespawn(CBasePlayer *this)

{
  int *piVar1;
  EHANDLE *this_00;
  float fVar2;
  entvars_t *peVar3;
  CBasePlayerItem *pCVar4;
  vec_t vVar5;
  globalvars_t *pgVar6;
  _func_void_int *p_Var7;
  uint uVar8;
  int iVar9;
  CBaseEntity *pCVar10;
  Vector local_3c;
  Vector local_30;
  Vector local_24;
  Vector local_18;
  
  this->forced_spawn = 1;
  (*g_engfuncs.pfnMessageBegin)(2,0x17,(float *)0x0,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x7d);
  p_Var7 = g_engfuncs.pfnWriteByte;
  uVar8 = (*g_engfuncs.pfnIndexOfEdict)
                    (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*p_Var7)(uVar8 & 0xff);
  (*g_engfuncs.pfnMessageEnd)();
  vVar5 = g_vecZero.x;
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.is_feigning != 0) {
    peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_feigning = 0;
    (peVar3->velocity).x = vVar5;
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
  iVar9 = EHANDLE::operator_int(this_00);
  if (iVar9 != 0) {
    pCVar10 = EHANDLE::operator->(this_00);
    (*pCVar10->_vptr_CBaseEntity[0x2d])(pCVar10,this,this,0,0);
    EHANDLE::operator=(this_00,(CBaseEntity *)0x0);
  }
  pgVar6 = gpGlobals;
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
  fVar2 = pgVar6->time;
  uVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.numflames = 0.0;
  this->m_flConcDuration = 0.0;
  this->m_flConcStartTime = 0.0;
  this->m_flNextSBarUpdateTime = fVar2 + 1.0;
  if ((uVar8 & 1) != 0) {
    uVar8 = uVar8 & 0xfffffffe;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar8;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.bRemoveGrenade = 1;
  }
  if ((uVar8 & 8) == 0) {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = uVar8 & 0x800;
  }
  else {
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.tfstate = (-(uint)((uVar8 & 0x800) == 0) & 0xfffff800) + 0x808;
  }
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar9 = peVar3->playerclass;
  if ((((iVar9 != 10) && (iVar9 != 0)) &&
      (iVar9 != (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.lastpc)) &&
     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.lastpc = iVar9,
     (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.exec_scripts != 0)) {
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
  iVar9 = CBaseAnimating::LookupActivity((CBaseAnimating *)this,1);
  peVar3->sequence = iVar9;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar3->flags & 0x4000) == 0) {
    local_18.x = 16.0;
    local_18.y = 16.0;
    local_18.z = 36.0;
    local_24.x = -16.0;
    local_24.y = -16.0;
    local_24.z = -36.0;
    UTIL_SetSize(peVar3,&local_24,&local_18);
    return;
  }
  local_30.x = 16.0;
  local_30.y = 16.0;
  local_30.z = 18.0;
  local_3c.x = -16.0;
  local_3c.y = -16.0;
  local_3c.z = -18.0;
  UTIL_SetSize(peVar3,&local_3c,&local_30);
  return;
}


// CBasePlayer::DropGoalItems  @ 00112b70  (line 8329)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DropGoalItems(CBasePlayer * this) */

void __thiscall CBasePlayer::DropGoalItems(CBasePlayer *this)

{
  CBaseEntity *Item;
  TraceResult TStack_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
  CBaseMonster::GetGunPosition(&local_24,&this->super_CBaseMonster);
  local_18.z = (gpGlobals->v_forward).z * 32.0 + local_24.z;
  local_18.y = (gpGlobals->v_forward).y * 32.0 + local_24.y;
  local_18.x = (gpGlobals->v_forward).x * 32.0 + local_24.x;
  UTIL_TraceHull(&local_24,&local_18,dont_ignore_monsters,1,
                 ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,&TStack_5c);
  if (TStack_5c.flFraction == 1.0) {
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


// CBasePlayer::EngineerUse  @ 00101560  (line 8359)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL EngineerUse(CBasePlayer * this, CBasePlayer * pPlayer) */

BOOL __thiscall CBasePlayer::EngineerUse(CBasePlayer *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  entvars_t *peVar4;
  int iVar5;
  
                    /* Unresolved local var: int iHealcost@[???]
                       Unresolved local var: int iHealam@[???] */
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar4->armortype == 0.0) {
    peVar4->armortype =
         (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.armor_allowed;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  iVar3 = 10;
  if ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_cells < 0xb) {
    iVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
  }
  fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor - peVar4->armorvalue;
  iVar5 = iVar3 * 5;
  if (fVar2 < (float)iVar5) {
    iVar5 = (int)fVar2;
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    iVar3 = (int)ROUND((float)iVar5 * 0.25);
  }
  if (0 < iVar5) {
    peVar4->armorvalue = (float)iVar5 + peVar4->armorvalue;
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.maxarmor;
    if (fVar2 < peVar4->armorvalue) {
      peVar4->armorvalue = fVar2;
    }
    piVar1 = &(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells;
    *piVar1 = *piVar1 - iVar3;
    EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,"items/r_item2.wav"
                   ,1.0,0.8,0,100);
  }
  return 1;
}


// CBasePlayer::UseSpecialSkill  @ 00112cd0  (line 8392)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void UseSpecialSkill(CBasePlayer * this) */

void __thiscall CBasePlayer::UseSpecialSkill(CBasePlayer *this)

{
  CBasePlayerItem *pCVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
  iVar2 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
  if (iVar2 != 0) {
    switch(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->playerclass) {
    case 1:
      TeamFortress_DisplayDetectionItems(this);
      return;
    case 2:
      pCVar1 = this->m_pActiveItem;
      if (pCVar1 != (CBasePlayerItem *)0x0) {
        bVar5 = gpGlobals->pStringBase +
                ((pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname
                == (char *)0x0;
        iVar2 = 0x16;
        pcVar3 = gpGlobals->pStringBase +
                 ((pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.pev)->classname;
        pcVar4 = "tf_weapon_sniperrifle";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
          pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
        } while (bVar5);
        if ((bVar5) &&
           ((float)pCVar1[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.m_pLink <= 0.0)
           ) {
                    /* WARNING: Could not recover jumptable at 0x00112e5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(pCVar1->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
            [0x5c])();
          return;
        }
      }
      break;
    case 3:
      if (this->m_pActiveItem != (CBasePlayerItem *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00112df5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x5d])();
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
  }
  return;
}


// LinkUserMessages  @ 00112e80  (line 8456)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void LinkUserMessages(void)

{
  if (gmsgHealth == 0) {
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
  }
  return;
}


// CBasePlayer::TeamFortress_CalcEMPDmgRad  @ 001002a0  (line 8526)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_CalcEMPDmgRad(CBasePlayer * this, float * damage,
   float * radius) */

void __thiscall
CBasePlayer::TeamFortress_CalcEMPDmgRad(CBasePlayer *this,float *damage,float *radius)

{
  float fVar1;
  
  fVar1 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.ammo_shells * 0.75 +
          (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.ammo_rockets * 1.5;
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


// CBasePlayer::TeamFortress_TakeEMPBlast  @ 00100360  (line 8537)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CBasePlayer * this, entvars_t * pevGren)
    */

void __thiscall CBasePlayer::TeamFortress_TakeEMPBlast(CBasePlayer *this,entvars_t *pevGren)

{
  float fVar1;
  float fVar2;
  BOOL BVar3;
  edict_t *peVar4;
  CBasePlayer *pOther;
  ushort in_FPUControlWord;
  float local_1c [2];
  undefined4 local_14;
  ushort local_10;
  ushort local_e;
  
                    /* Unresolved local var: CBaseEntity * pThrower@[DW_OP_reg7(EDI)]
                       Unresolved local var: CBaseEntity * pGrenade@[???]
                       Unresolved local var: float radius@[???]
                       Unresolved local var: float damage@[???] */
  peVar4 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar4 == (edict_t *)0x0) &&
     (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
    pOther = (CBasePlayer *)0x0;
  }
  else {
    pOther = peVar4->pvPrivateData;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pevGren->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.pev)->playerclass != 0) &&
     (((((int)gpGlobals->teamplay & 0x10U) == 0 ||
       (BVar3 = CBaseEntity::IsAlly((CBaseEntity *)this,(CBaseEntity *)pOther), BVar3 == 0)) ||
      (this == pOther)))) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x3c])(this,local_1c,&local_14);
    fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.ammo_shells;
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    fVar1 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.ammo_rockets;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_shells = (int)(fVar2 - ROUND(fVar2 * 0.25));
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    local_10 = in_FPUControlWord & 0xf3ff | 0x800;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_rockets = (int)(fVar1 - ROUND(fVar1 * 0.25));
    local_e = in_FPUControlWord;
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->playerclass != 9) {
      fVar1 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.ammo_cells;
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
      local_e = in_FPUControlWord & 0xf3ff | 0x800;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_cells = (int)(fVar1 - ROUND(fVar1 * 0.25));
      local_10 = in_FPUControlWord;
    }
    if (0.0 < local_1c[0]) {
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x3b])(this,pevGren,local_1c[0],local_14);
    }
  }
  return;
}


// CBasePlayer::TeamFortress_TakeConcussionBlast  @ 00100e20  (line 8562)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeConcussionBlast(CBasePlayer * this, entvars_t *
   pevGren, float bouncemax) */

void __thiscall
CBasePlayer::TeamFortress_TakeConcussionBlast(CBasePlayer *this,entvars_t *pevGren,float bouncemax)

{
  entvars_t *peVar1;
  char *pcVar2;
  string_t sVar3;
  float __x;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  BOOL BVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  edict_t *peVar12;
  char *pcVar13;
  void *pvVar14;
  CBaseEntity *pOther;
  float fVar15;
  float fVar16;
  char *local_2c;
  
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: CBaseEntity * pGren@[???]
                       Unresolved local var: float bounceval@[???]
                       Unresolved local var: CBaseEntity * pOwner@[???] */
  iVar7 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x22])(this);
  if ((iVar7 != 0) &&
     (peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev, peVar1->playerclass != 0)) {
                    /* Unresolved local var: Vector delta@[???]
                       Unresolved local var: CBaseEntity * pGren@[DW_OP_reg7(EDI)]
                       Unresolved local var: float bounceval@[???]
                       Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg7(EDI)] */
    fVar5 = (peVar1->origin).z - (pevGren->origin).z;
    fVar6 = (peVar1->origin).y - (pevGren->origin).y;
    peVar12 = pevGren->pContainingEntity;
    fVar4 = (peVar1->origin).x - (pevGren->origin).x;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar12 == (edict_t *)0x0) &&
       (peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar12 == (edict_t *)0x0)) {
      pOther = (CBaseEntity *)0x0;
    }
    else {
      pOther = peVar12->pvPrivateData;
    }
    __x = fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4;
    fVar16 = SQRT(__x);
    fVar15 = fVar16;
    if (NAN(fVar16)) {
      fVar15 = sqrtf(__x);
    }
    fVar15 = (bouncemax - fVar15 * 0.5) * 0.03;
    if (NAN(fVar16)) {
      fVar16 = sqrtf(__x);
    }
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (fVar16 < 16.0) {
      fVar5 = (peVar1->velocity).z * 0.33;
      fVar6 = (peVar1->velocity).y * 0.33;
      fVar4 = (peVar1->velocity).x * 0.33;
    }
    (peVar1->velocity).x = fVar4;
    (peVar1->velocity).y = fVar6;
    (peVar1->velocity).z = fVar5;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar1->velocity).x = (peVar1->velocity).x * fVar15;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar1->velocity).y = (peVar1->velocity).y * fVar15;
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar1->velocity).z = fVar15 * (peVar1->velocity).z * 1.5;
    if ((((int)gpGlobals->teamplay & 0x1eU) == 0) ||
       ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no < 1)) {
      peVar12 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity;
    }
    else {
      BVar8 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther);
      peVar12 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->pContainingEntity;
      if ((BVar8 != 0) && (pevGren->owner != peVar12)) {
        return;
      }
    }
    (*g_engfuncs.pfnMessageBegin)(1,gmsgDamage,(float *)0x0,peVar12);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteByte)(0);
    (*g_engfuncs.pfnWriteLong)(0x200);
    (*g_engfuncs.pfnWriteCoord)((pevGren->origin).x);
    (*g_engfuncs.pfnWriteCoord)((pevGren->origin).y);
    (*g_engfuncs.pfnWriteCoord)((pevGren->origin).z);
    (*g_engfuncs.pfnMessageEnd)();
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0x40])(this,pevGren);
    peVar12 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar12 == (edict_t *)0x0) &&
       (peVar12 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar12 == (edict_t *)0x0)) {
      pvVar14 = (void *)0x0;
    }
    else {
      pvVar14 = peVar12->pvPrivateData;
    }
    iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.team_no;
    local_2c = "SPECTATOR";
    if (iVar7 != 0) {
      local_2c = GetTeamName(iVar7);
    }
    pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)
                       (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    iVar7 = (*g_engfuncs.pfnGetPlayerUserId)
                      (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
    pcVar2 = gpGlobals->pStringBase;
    sVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->netname;
    pcVar13 = "SPECTATOR";
    if (*(int *)((int)pvVar14 + 0x138) != 0) {
      pcVar13 = GetTeamName(*(int *)((int)pvVar14 + 0x138));
    }
    pcVar10 = (*g_engfuncs.pfnGetPlayerAuthId)(pevGren->owner);
    iVar11 = (*g_engfuncs.pfnGetPlayerUserId)(pevGren->owner);
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Concussion_Grenade\" against \"%s<%i><%s><%s>\"\n"
                   ,gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar14 + 4) + 0x1d0),iVar11,
                   pcVar10,pcVar13,pcVar2 + sVar3,iVar7,pcVar9,local_2c);
  }
  return;
}


// CBasePlayer::TeamFortress_Concuss  @ 00100310  (line 8617)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_Concuss(CBasePlayer * this, entvars_t * pevGren) */

void __thiscall CBasePlayer::TeamFortress_Concuss(CBasePlayer *this,entvars_t *pevGren)

{
  float fVar1;
  globalvars_t *pgVar2;
  
  this->m_iConcussion = 100;
  pgVar2 = gpGlobals;
  this->m_iConcStartVal = 100;
  fVar1 = pgVar2->time;
  this->m_flConcDuration = 15.0;
  this->m_flConcStartTime = fVar1;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass != 5) {
    return;
  }
  this->m_flConcDuration = 7.0;
  return;
}


// CBasePlayer::TeamFortress_ThrowPrimedGrenade  @ 00113520  (line 8627)

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


// CBasePlayer::TeamFortress_PrimeGrenade  @ 00113540  (line 8634)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_PrimeGrenade(CBasePlayer * this, int iWhichType) */

void __thiscall CBasePlayer::TeamFortress_PrimeGrenade(CBasePlayer *this,int iWhichType)

{
  int iVar1;
  int *piVar2;
  
                    /* Unresolved local var: CGrenade * pGrenade@[???]
                       Unresolved local var: int grentype@[???]
                       Unresolved local var: int * pNumGrenades@[???] */
  if ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.tfstate & 0x401U) == 0) &&
     (iVar1 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity._vptr_CBaseEntity[0x22])(this), iVar1 != 0)) {
    if (iWhichType == 1) {
      iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tp_grenades_1;
      piVar2 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.no_grenades_1;
    }
    else {
      iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tp_grenades_2;
      piVar2 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.no_grenades_2;
    }
    if (0 < *piVar2) {
      switch(iVar1) {
      default:
        goto switchD_001135a1_caseD_0;
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
      *piVar2 = *piVar2 + -1;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.m_iPrimedGrenType = iWhichType;
      piVar2 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.tfstate;
      *piVar2 = *piVar2 | 1;
      EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,"weapons/ax1.wav"
                     ,0.9,0.8,0,100);
      return;
    }
  }
switchD_001135a1_caseD_0:
  return;
}


// CBasePlayer::CheckUncoveringSpies  @ 00101260  (line 8710)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckUncoveringSpies(CBasePlayer * this, CBasePlayer * pPlayer) */

void __thiscall CBasePlayer::CheckUncoveringSpies(CBasePlayer *this,CBasePlayer *pPlayer)

{
  char *pcVar1;
  string_t sVar2;
  int in_EAX;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  CBasePlayer *in_EDX;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar6 = *(int *)(in_EAX + 0x144) + 1;
  *(int *)(in_EAX + 0x144) = iVar6;
  if (*(int *)(in_EAX + 0x138) != 0) {
    teamfrags[*(int *)(in_EAX + 0x138)] = teamfrags[*(int *)(in_EAX + 0x138)] + 1;
  }
  *(float *)(*(int *)(in_EAX + 4) + 0x164) = (float)iVar6;
  Spy_RemoveDisguise(in_EDX);
  pcVar7 = "SPECTATOR";
  UTIL_ClientPrintAll(1,"#Spy_uncovered",
                      gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1d0),(char *)0x0,
                      (char *)0x0,(char *)0x0);
  iVar6 = (in_EDX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if (iVar6 != 0) {
    pcVar7 = GetTeamName(iVar6);
  }
  pcVar3 = (*g_engfuncs.pfnGetPlayerAuthId)
                     (((in_EDX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  iVar6 = (*g_engfuncs.pfnGetPlayerUserId)
                    (((in_EDX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  pcVar1 = gpGlobals->pStringBase;
  sVar2 = ((in_EDX->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->netname;
  pcVar8 = "SPECTATOR";
  if (*(int *)(in_EAX + 0x138) != 0) {
    pcVar8 = GetTeamName(*(int *)(in_EAX + 0x138));
  }
  pcVar4 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)(in_EAX + 4) + 0x208));
  iVar5 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)(in_EAX + 4) + 0x208));
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Discovered_Spy\" against \"%s<%i><%s><%s>\"\n",
                 gpGlobals->pStringBase + *(int *)(*(int *)(in_EAX + 4) + 0x1d0),iVar5,pcVar4,pcVar8
                 ,pcVar1 + sVar2,iVar6,pcVar3,pcVar7);
  return;
}


// CBasePlayer::CheckUncoveringSpies  @ 001136b0  (line 8711)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void CheckUncoveringSpies(CBasePlayer * this, CBasePlayer * pPlayer) */

void __thiscall CBasePlayer::CheckUncoveringSpies(CBasePlayer *this,CBasePlayer *pPlayer)

{
  int iVar1;
  BOOL BVar2;
  
  iVar1 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass;
  if ((iVar1 == 1) || (iVar1 == 8)) {
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


// CBasePlayer::ClientHearVox  @ 00113720  (line 8743)

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
  if (*pSentence != '#') {
    pcVar2 = UTIL_VarArgs("spk \"%s\"\n",pSentence);
    (*p_Var1)(pcVar2);
                    /* WARNING: Could not recover jumptable at 0x00113780. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnMessageEnd)();
    return;
  }
  pcVar2 = UTIL_VarArgs("spk %s\n",pSentence);
  (*p_Var1)(pcVar2);
                    /* WARNING: Could not recover jumptable at 0x001137a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnMessageEnd)();
  return;
}


// CBasePlayer::PlayerTouch  @ 00101fc0  (line 8761)

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
  float fVar8;
  CBasePlayer *pCVar9;
  CBasePlayer *pCVar10;
  TraceResult local_5c;
  Vector local_18;
  
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  iVar3 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if (iVar3 != 2) {
    return;
  }
  iVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass;
  if (iVar3 == 8) {
LAB_00102218:
    pCVar9 = this;
    pCVar10 = (CBasePlayer *)pOther;
    BVar4 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther);
    if ((BVar4 == 0) && ((pOther->undercover_team != 0 || (pOther->undercover_skin != 0)))) {
      CheckUncoveringSpies(pCVar9,pCVar10);
    }
    iVar3 = pOther->pev->playerclass;
    if ((iVar3 == 1) || (iVar3 == 8)) {
LAB_001021db:
      pCVar9 = (CBasePlayer *)pOther;
      pCVar10 = this;
      BVar4 = CBaseEntity::IsAlly(pOther,(CBaseEntity *)this);
      if ((BVar4 == 0) &&
         (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.undercover_team != 0 ||
          ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.undercover_skin != 0)))) {
        CheckUncoveringSpies(pCVar9,pCVar10);
      }
    }
  }
  else if (pOther->pev->playerclass == 8) {
    if (iVar3 == 1) goto LAB_00102218;
    goto LAB_001021db;
  }
  BVar4 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther);
  if (BVar4 == 0) {
    return;
  }
                    /* Unresolved local var: CBasePlayer * pPlayer@[???] */
  peVar5 = pOther->pev;
  fVar1 = (peVar5->velocity).x;
  fVar8 = (peVar5->velocity).y;
  fVar2 = (peVar5->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar8 * fVar8 + fVar1 * fVar1;
  fVar8 = SQRT(fVar1);
  if (NAN(fVar8)) {
    fVar8 = sqrtf(fVar1);
  }
  if (50.0 <= fVar8) {
    return;
  }
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (peVar5->velocity).x;
  fVar8 = (peVar5->velocity).y;
  fVar2 = (peVar5->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar8 * fVar8 + fVar1 * fVar1;
  fVar8 = SQRT(fVar1);
  if (NAN(fVar8)) {
    fVar8 = sqrtf(fVar1);
  }
  if ((fVar8 <= 55.0) &&
     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.items & 0x60000U) == 0)) {
    return;
  }
                    /* Unresolved local var: TraceResult tr@[???] */
  UTIL_MakeVectors(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                     super_CBaseDelay.super_CBaseEntity.pev)->v_angle);
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.z = (gpGlobals->v_forward).z * 24.0 + (peVar5->origin).z;
  local_18.y = (gpGlobals->v_forward).y * 24.0 + (peVar5->origin).y;
  local_18.x = (gpGlobals->v_forward).x * 24.0 + (peVar5->origin).x;
  UTIL_TraceLine(&peVar5->origin,&local_18,dont_ignore_monsters,peVar5->pContainingEntity,&local_5c)
  ;
  if (local_5c.pHit == (edict_t *)0x0) {
    return;
  }
  iVar3 = (*g_engfuncs.pfnEntOffsetOfPEntity)(local_5c.pHit);
  if (iVar3 == 0) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pHit@[DW_OP_reg2(EDX)] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (local_5c.pHit == (edict_t *)0x0) {
    local_5c.pHit = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    pCVar6 = (CBaseEntity *)0x0;
    if (local_5c.pHit == (edict_t *)0x0) goto LAB_00102136;
  }
  pCVar6 = (local_5c.pHit)->pvPrivateData;
LAB_00102136:
  if (pOther == pCVar6) {
    if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.items & 0x60000U) == 0) {
      if ((pOther->items & 0x60000U) != 0) {
        return;
      }
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
                    /* Unresolved local var: float flLen@[???] */
      fVar1 = (peVar5->velocity).x;
      fVar8 = (peVar5->velocity).y;
      fVar2 = (peVar5->velocity).z;
      fVar7 = sqrtf(fVar2 * fVar2 + fVar8 * fVar8 + fVar1 * fVar1);
      fVar1 = 0.0;
      if (fVar7 == 0.0) {
        fVar8 = 1.0;
        fVar2 = 0.0;
      }
      else {
        fVar7 = 1.0 / fVar7;
        fVar8 = (peVar5->velocity).z * fVar7;
        fVar2 = (peVar5->velocity).y * fVar7;
        fVar1 = (peVar5->velocity).x * fVar7;
      }
      peVar5 = pOther->pev;
      fVar7 = 30.0;
    }
    else {
      peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
                    /* Unresolved local var: float flLen@[???] */
      fVar1 = (peVar5->velocity).x;
      fVar8 = (peVar5->velocity).y;
      fVar2 = (peVar5->velocity).z;
      fVar8 = sqrtf(fVar2 * fVar2 + fVar8 * fVar8 + fVar1 * fVar1);
      fVar1 = 0.0;
      if (fVar8 == 0.0) {
        fVar8 = 1.0;
        fVar2 = 0.0;
      }
      else {
        fVar1 = 1.0 / fVar8;
        fVar8 = (peVar5->velocity).z * fVar1;
        fVar2 = (peVar5->velocity).y * fVar1;
        fVar1 = (peVar5->velocity).x * fVar1;
      }
      peVar5 = pOther->pev;
      fVar7 = 120.0;
    }
    (peVar5->velocity).x = fVar7 * fVar1 + (peVar5->velocity).x;
    (peVar5->velocity).y = fVar2 * fVar7 + (peVar5->velocity).y;
    (peVar5->velocity).z = fVar8 * fVar7 + (peVar5->velocity).z;
  }
  return;
}


// CBasePlayer::DB_GetPlayerClassName  @ 001137b0  (line 8806)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: char * DB_GetPlayerClassName(CBasePlayer * this) */

char * __thiscall CBasePlayer::DB_GetPlayerClassName(CBasePlayer *this)

{
  return sClassNames
         [((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->playerclass];
}


// PrototypeWriteDamage  @ 001137d0  (line 8812)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PrototypeWriteDamage(void)

{
  FILE *__stream;
  
                    /* Unresolved local var: FILE * fp@[???] */
  __stream = fopen("prototype.txt","a");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%6.2f : Damages %6.2f %6.2f %6.2f : Factors %6.2f %6.2f %6.2f %6.2f\n",
            (double)gpGlobals->time,(double)gfPrototypeTotalDamage,(double)gfPrototypeExtraDamage,
            (double)gfPrototypeLessDamage,(double)teamadvantage[1],(double)teamadvantage[2],
            (double)teamadvantage[3],(double)teamadvantage[4]);
    fclose(__stream);
  }
  return;
}


