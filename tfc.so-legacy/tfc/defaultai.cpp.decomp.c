// Ghidra decompilation of functions from tfc/defaultai.cpp
// 3 functions, ordered by original source line

// CBaseMonster::ScheduleFromName  @ 000c2c60  (line 1019)

/* DWARF original prototype: Schedule_t * ScheduleFromName(CBaseMonster * this, char * pName) */

Schedule_t * __thiscall CBaseMonster::ScheduleFromName(CBaseMonster *this,char *pName)

{
  Schedule_t *pSVar1;
  char *__s2;
  int iVar2;
  Schedule_t **ppSVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (pName == (char *)0x0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"%s set to unnamed schedule!\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
  }
  else {
    ppSVar3 = m_scheduleList;
    do {
      while( true ) {
        pSVar1 = *ppSVar3;
        __s2 = pSVar1->pName;
        if (__s2 != (char *)0x0) break;
        ppSVar3 = ppSVar3 + 1;
        (*g_engfuncs.pfnAlertMessage)(at_console,"Unnamed schedule!\n");
        if ((Schedule_t *)ppSVar3 == slTakeCoverFromEnemy) {
          return (Schedule_t *)0x0;
        }
      }
      iVar2 = strcasecmp(pName,__s2);
      if (iVar2 == 0) {
        return pSVar1;
      }
      ppSVar3 = ppSVar3 + 1;
    } while ((Schedule_t *)ppSVar3 != slTakeCoverFromEnemy);
  }
  return (Schedule_t *)0x0;
}


// CBaseMonster::ScheduleInList  @ 000c2d00  (line 1025)

/* DWARF original prototype: Schedule_t * ScheduleInList(CBaseMonster * this, char * pName,
   Schedule_t * * pList, int listCount) */

Schedule_t * __thiscall
CBaseMonster::ScheduleInList(CBaseMonster *this,char *pName,Schedule_t **pList,int listCount)

{
  Schedule_t *pSVar1;
  char *__s2;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (pName == (char *)0x0) {
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"%s set to unnamed schedule!\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
  }
  else {
    iVar3 = 0;
    if (0 < listCount) {
      do {
        while( true ) {
          pSVar1 = pList[iVar3];
          __s2 = pSVar1->pName;
          if (__s2 != (char *)0x0) break;
          iVar3 = iVar3 + 1;
          (*g_engfuncs.pfnAlertMessage)(at_console,"Unnamed schedule!\n");
          if (iVar3 == listCount) {
            return (Schedule_t *)0x0;
          }
        }
        iVar2 = strcasecmp(pName,__s2);
        if (iVar2 == 0) {
          return pSVar1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != listCount);
    }
  }
  return (Schedule_t *)0x0;
}


// CBaseMonster::GetScheduleOfType  @ 000c2da0  (line 1053)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Schedule_t * GetScheduleOfType(CBaseMonster * this, int Type) */

Schedule_t * __thiscall CBaseMonster::GetScheduleOfType(CBaseMonster *this,int Type)

{
  uint uVar1;
  int32 iVar2;
  int iVar3;
  Schedule_t *pSVar4;
  
  switch(Type) {
  default:
    pSVar4 = slIdleStand;
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"GetScheduleOfType()\nNo CASE for Schedule Type %d!\n",Type);
    break;
  case 1:
    pSVar4 = slIdleStand;
    iVar2 = (*g_engfuncs.pfnRandomLong)(0,0xe);
    if ((iVar2 == 0) &&
       (iVar3 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                  _vptr_CBaseEntity[0x72])(this), iVar3 != 0)) {
      pSVar4 = slActiveIdle;
    }
    break;
  case 2:
    pSVar4 = slIdleWalk;
    break;
  case 3:
    pSVar4 = slWakeAngry;
    break;
  case 5:
    pSVar4 = slAlertFace;
    break;
  case 6:
    pSVar4 = slAlertSmallFlinch;
    break;
  case 8:
    pSVar4 = slAlertStand;
    break;
  case 9:
    pSVar4 = slInvestigateSound;
    break;
  case 10:
    pSVar4 = slCombatFace;
    break;
  case 0xb:
    pSVar4 = slCombatStand;
    break;
  case 0xc:
    pSVar4 = slChaseEnemy;
    break;
  case 0xd:
  case 0x29:
    pSVar4 = slFail;
    break;
  case 0xe:
    pSVar4 = slVictoryDance;
    break;
  case 0x11:
    pSVar4 = slSmallFlinch;
    break;
  case 0x12:
    pSVar4 = slTakeCoverFromEnemy;
    break;
  case 0x13:
    pSVar4 = slTakeCoverFromBestSound;
    break;
  case 0x14:
    pSVar4 = slTakeCoverFromOrigin;
    break;
  case 0x15:
    pSVar4 = slCower;
    break;
  case 0x16:
    pSVar4 = slPrimaryMeleeAttack;
    break;
  case 0x17:
    pSVar4 = slSecondaryMeleeAttack;
    break;
  case 0x18:
    pSVar4 = slRangeAttack1;
    break;
  case 0x19:
    pSVar4 = slRangeAttack2;
    break;
  case 0x1a:
    pSVar4 = slSpecialAttack1;
    break;
  case 0x1b:
    pSVar4 = slSpecialAttack2;
    break;
  case 0x1c:
    pSVar4 = slStandoff;
    break;
  case 0x1d:
    pSVar4 = slArmWeapon;
    break;
  case 0x1e:
    pSVar4 = slReload;
    break;
  case 0x20:
    pSVar4 = slAmbush;
    break;
  case 0x21:
    pSVar4 = slDie;
    break;
  case 0x22:
    pSVar4 = slIdleTrigger;
    break;
  case 0x26:
    pSVar4 = slBarnacleVictimGrab;
    break;
  case 0x27:
    pSVar4 = slBarnacleVictimChomp;
    break;
  case 0x28:
    if (this->m_pCine == (CCineMonster *)0x0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"Script failed for %s\n",
                 gpGlobals->pStringBase +
                 ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->classname);
      CineCleanup(this);
                    /* WARNING: Could not recover jumptable at 0x000c309e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pSVar4 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])();
      return pSVar4;
    }
    uVar1 = this->m_pCine->m_fMoveTo;
    pSVar4 = (Schedule_t *)0x0;
    if (uVar1 < 6) {
      pSVar4 = *(Schedule_t **)(CSWTCH_26 + uVar1 * 4);
    }
  }
  return pSVar4;
}


