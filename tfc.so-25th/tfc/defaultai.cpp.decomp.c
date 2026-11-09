// Ghidra decompilation of functions from tfc/defaultai.cpp
// 3 functions, ordered by original source line

// CBaseMonster::ScheduleFromName  @ 000837e0  (line 1019)

/* DWARF original prototype: Schedule_t * ScheduleFromName(CBaseMonster * this, char * pName) */

Schedule_t * __thiscall CBaseMonster::ScheduleFromName(CBaseMonster *this,char *pName)

{
  Schedule_t *pSVar1;
  char *__s2;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (pName == (char *)0x0) {
                    /* Unresolved local var: int i@[???] */
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"%s set to unnamed schedule!\n",
               gpGlobals->pStringBase +
               ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
               pev)->classname);
  }
  else {
    iVar3 = 0;
    do {
      while( true ) {
        pSVar1 = *(Schedule_t **)((int)m_scheduleList + iVar3);
        __s2 = pSVar1->pName;
        if (__s2 != (char *)0x0) break;
        iVar3 = iVar3 + 4;
        (*g_engfuncs.pfnAlertMessage)(at_console,"Unnamed schedule!\n");
        if (iVar3 == 0x98) {
          return (Schedule_t *)0x0;
        }
      }
      iVar2 = strcasecmp(pName,__s2);
      if (iVar2 == 0) {
        return pSVar1;
      }
      iVar3 = iVar3 + 4;
    } while (iVar3 != 0x98);
  }
  return (Schedule_t *)0x0;
}


// CBaseMonster::ScheduleInList  @ 00083890  (line 1025)

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
          if (listCount == iVar3) {
            return (Schedule_t *)0x0;
          }
        }
        iVar2 = strcasecmp(pName,__s2);
        if (iVar2 == 0) {
          return pSVar1;
        }
        iVar3 = iVar3 + 1;
      } while (listCount != iVar3);
    }
  }
  return (Schedule_t *)0x0;
}


// CBaseMonster::GetScheduleOfType  @ 00083940  (line 1053)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Schedule_t * GetScheduleOfType(CBaseMonster * this, int Type) */

Schedule_t * __thiscall CBaseMonster::GetScheduleOfType(CBaseMonster *this,int Type)

{
  int32 iVar1;
  Schedule_t *pSVar2;
  int iVar3;
  
  switch(Type) {
  default:
    (*g_engfuncs.pfnAlertMessage)
              (at_console,"GetScheduleOfType()\nNo CASE for Schedule Type %d!\n",Type);
    pSVar2 = slIdleStand;
    break;
  case 1:
    iVar1 = (*g_engfuncs.pfnRandomLong)(0,0xe);
    if (iVar1 == 0) {
      iVar3 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                _vptr_CBaseEntity[0x72])(this);
      if (iVar3 != 0) {
        return slActiveIdle;
      }
    }
    pSVar2 = slIdleStand;
    break;
  case 2:
    pSVar2 = slIdleWalk;
    break;
  case 3:
    pSVar2 = slWakeAngry;
    break;
  case 5:
    pSVar2 = slAlertFace;
    break;
  case 6:
    pSVar2 = slAlertSmallFlinch;
    break;
  case 8:
    pSVar2 = slAlertStand;
    break;
  case 9:
    pSVar2 = slInvestigateSound;
    break;
  case 10:
    pSVar2 = slCombatFace;
    break;
  case 0xb:
    pSVar2 = slCombatStand;
    break;
  case 0xc:
    pSVar2 = slChaseEnemy;
    break;
  case 0xd:
  case 0x29:
    pSVar2 = slFail;
    break;
  case 0xe:
    pSVar2 = slVictoryDance;
    break;
  case 0x11:
    pSVar2 = slSmallFlinch;
    break;
  case 0x12:
    pSVar2 = slTakeCoverFromEnemy;
    break;
  case 0x13:
    pSVar2 = slTakeCoverFromBestSound;
    break;
  case 0x14:
    pSVar2 = slTakeCoverFromOrigin;
    break;
  case 0x15:
    pSVar2 = slCower;
    break;
  case 0x16:
    pSVar2 = slPrimaryMeleeAttack;
    break;
  case 0x17:
    pSVar2 = slSecondaryMeleeAttack;
    break;
  case 0x18:
    pSVar2 = slRangeAttack1;
    break;
  case 0x19:
    pSVar2 = slRangeAttack2;
    break;
  case 0x1a:
    pSVar2 = slSpecialAttack1;
    break;
  case 0x1b:
    pSVar2 = slSpecialAttack2;
    break;
  case 0x1c:
    pSVar2 = slStandoff;
    break;
  case 0x1d:
    pSVar2 = slArmWeapon;
    break;
  case 0x1e:
    pSVar2 = slReload;
    break;
  case 0x20:
    pSVar2 = slAmbush;
    break;
  case 0x21:
    pSVar2 = slDie;
    break;
  case 0x22:
    pSVar2 = slIdleTrigger;
    break;
  case 0x26:
    pSVar2 = slBarnacleVictimGrab;
    break;
  case 0x27:
    pSVar2 = slBarnacleVictimChomp;
    break;
  case 0x28:
    if (this->m_pCine == (CCineMonster *)0x0) {
      (*g_engfuncs.pfnAlertMessage)
                (at_aiconsole,"Script failed for %s\n",
                 gpGlobals->pStringBase +
                 ((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 pev)->classname);
      CineCleanup(this);
                    /* WARNING: Could not recover jumptable at 0x00083c55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pSVar2 = (Schedule_t *)
               (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                 _vptr_CBaseEntity[0x5c])();
      return pSVar2;
    }
    switch(this->m_pCine->m_fMoveTo) {
    case 0:
    case 4:
      pSVar2 = slWaitScript;
      break;
    case 1:
      pSVar2 = slWalkToScript;
      break;
    case 2:
      pSVar2 = slRunToScript;
      break;
    default:
      pSVar2 = (Schedule_t *)0x0;
      break;
    case 5:
      pSVar2 = slFaceScript;
    }
  }
  return pSVar2;
}


