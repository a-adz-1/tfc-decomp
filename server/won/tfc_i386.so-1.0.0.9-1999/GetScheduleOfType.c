// GetScheduleOfType__12CBaseMonsteri  @ 000a7180
undefined1 * GetScheduleOfType__12CBaseMonsteri(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  switch(param_2) {
  case 1:
    iVar1 = (*DAT_00175628)(0,0xe);
    if ((iVar1 == 0) && (iVar1 = (**(code **)(param_1[0xf2] + 0x1c4))(param_1), iVar1 != 0)) {
      return slActiveIdle;
    }
    goto LAB_000a747f;
  case 2:
    puVar2 = slIdleWalk;
    break;
  case 3:
    puVar2 = slWakeAngry;
    break;
  default:
    (*DAT_001755b4)(1,"GetScheduleOfType()\nNo CASE for Schedule Type %d!\n",param_2);
LAB_000a747f:
    puVar2 = slIdleStand;
    break;
  case 5:
    puVar2 = slAlertFace;
    break;
  case 6:
    puVar2 = slAlertSmallFlinch;
    break;
  case 8:
    puVar2 = slAlertStand;
    break;
  case 9:
    puVar2 = slInvestigateSound;
    break;
  case 10:
    puVar2 = slCombatFace;
    break;
  case 0xb:
    puVar2 = slCombatStand;
    break;
  case 0xc:
    puVar2 = slChaseEnemy;
    break;
  case 0xd:
  case 0x29:
    puVar2 = slFail;
    break;
  case 0xe:
    puVar2 = slVictoryDance;
    break;
  case 0x11:
    puVar2 = slSmallFlinch;
    break;
  case 0x12:
    puVar2 = slTakeCoverFromEnemy;
    break;
  case 0x13:
    puVar2 = slTakeCoverFromBestSound;
    break;
  case 0x14:
    puVar2 = slTakeCoverFromOrigin;
    break;
  case 0x15:
    puVar2 = slCower;
    break;
  case 0x16:
    puVar2 = slPrimaryMeleeAttack;
    break;
  case 0x17:
    puVar2 = slSecondaryMeleeAttack;
    break;
  case 0x18:
    puVar2 = slRangeAttack1;
    break;
  case 0x19:
    puVar2 = slRangeAttack2;
    break;
  case 0x1a:
    puVar2 = slSpecialAttack1;
    break;
  case 0x1b:
    puVar2 = slSpecialAttack2;
    break;
  case 0x1c:
    puVar2 = slStandoff;
    break;
  case 0x1d:
    puVar2 = slArmWeapon;
    break;
  case 0x1e:
    puVar2 = slReload;
    break;
  case 0x20:
    puVar2 = slAmbush;
    break;
  case 0x21:
    puVar2 = slDie;
    break;
  case 0x22:
    puVar2 = slIdleTrigger;
    break;
  case 0x26:
    puVar2 = slBarnacleVictimGrab;
    break;
  case 0x27:
    puVar2 = slBarnacleVictimChomp;
    break;
  case 0x28:
    if (param_1[0x183] == 0) {
      (*DAT_001755b4)(2,"Script failed for %s\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      CineCleanup__12CBaseMonster(param_1);
      puVar2 = (undefined1 *)(**(code **)(param_1[0xf2] + 0x16c))(param_1,1);
    }
    else {
      switch(*(undefined4 *)(param_1[0x183] + 0x61c)) {
      case 0:
      case 4:
        puVar2 = slWaitScript;
        break;
      case 1:
        puVar2 = slWalkToScript;
        break;
      case 2:
        puVar2 = slRunToScript;
        break;
      default:
        puVar2 = (undefined1 *)0x0;
        break;
      case 5:
        puVar2 = slFaceScript;
      }
    }
  }
  return puVar2;
}


// GetScheduleOfType__12CTalkMonsteri  @ 000f2bb0
undefined1 * GetScheduleOfType__12CTalkMonsteri(int *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  undefined1 *puVar5;
  longdouble lVar6;
  
  switch(param_2) {
  case 1:
    if ((*(byte *)(param_1 + 0x184) & 8) == 0) {
      return slIdleHello;
    }
    if (((*(byte *)(param_1 + 0x184) & 0x10) != 0) ||
       (*(float *)(*param_1 + 400) * 0.75 < *(float *)(*param_1 + 0x140))) {
      if (((*(byte *)(param_1 + 0x184) & 0x20) != 0) ||
         (*(float *)(*param_1 + 400) * 0.5 < *(float *)(*param_1 + 0x140))) {
        iVar4 = FOkToSpeak__12CTalkMonster(param_1);
        if ((iVar4 != 0) && (iVar4 = (*DAT_00175628)(0,param_1[0x185] * 2), iVar4 == 0)) {
          return slIdleSpeak;
        }
        iVar4 = IsTalking__12CTalkMonster(param_1);
        if (((iVar4 == 0) && ((*(byte *)((int)param_1 + 0x46e) & 0x20) != 0)) &&
           (iVar4 = (*DAT_00175628)(0,6), iVar4 == 0)) {
          iVar4 = (*DAT_001755e0)(1);
          if (iVar4 != 0) {
            UTIL_MakeVectors__FRC6Vector(iVar4 + 300);
            bVar3 = false;
            fVar1 = *(float *)(iVar4 + 0xe4) - *(float *)(*param_1 + 8);
            fVar2 = *(float *)(iVar4 + 0xe8) - *(float *)(*param_1 + 0xc);
            if ((SQRT(fVar2 * fVar2 + fVar1 * fVar1) < 128.0) &&
               (lVar6 = (longdouble)
                        UTIL_DotPoints__FRC6VectorN20(iVar4 + 0xe4,*param_1 + 8,gpGlobals + 0x28),
               (longdouble)(float)param_1[0x134] <= lVar6)) {
              bVar3 = true;
            }
            if (bVar3) {
              return slTlkIdleWatchClient + 0x14;
            }
            return slTlkIdleWatchClient;
          }
          goto switchD_000f2bcb_caseD_2;
        }
        iVar4 = IsTalking__12CTalkMonster(param_1);
        if (iVar4 != 0) {
          return slTlkIdleEyecontact;
        }
      }
      else {
        iVar4 = param_1[0xf2];
        lVar6 = (longdouble)(*DAT_0017562c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
        (**(code **)(iVar4 + 0x180))(param_1,param_1[0x198],(float)lVar6);
        *(byte *)(param_1 + 0x184) = *(byte *)(param_1 + 0x184) | 0x20;
      }
    }
    else {
      iVar4 = param_1[0xf2];
      lVar6 = (longdouble)(*DAT_0017562c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
      (**(code **)(iVar4 + 0x180))(param_1,param_1[0x197],(float)lVar6);
      *(byte *)(param_1 + 0x184) = *(byte *)(param_1 + 0x184) | 0x10;
    }
    goto LAB_000f2cb5;
  default:
switchD_000f2bcb_caseD_2:
    puVar5 = (undefined1 *)GetScheduleOfType__12CBaseMonsteri(param_1,param_2);
    break;
  case 0xf:
    iVar4 = (*DAT_00175628)(0,99);
    if (iVar4 < 2) {
      return slIdleSpeakWait;
    }
LAB_000f2cb5:
    puVar5 = slIdleStand;
    break;
  case 0x2c:
    puVar5 = slMoveAway;
    break;
  case 0x2d:
    puVar5 = slMoveAwayFollow;
    break;
  case 0x2e:
    puVar5 = slMoveAwayFail;
  }
  return puVar5;
}


// GetScheduleOfType__13CSquadMonsteri  @ 000f0190
undefined1 * GetScheduleOfType__13CSquadMonsteri(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (param_2 == 0xd) {
    puVar1 = slChaseEnemyFailed;
  }
  else {
    puVar1 = (undefined1 *)GetScheduleOfType__12CBaseMonsteri(param_1,param_2);
  }
  return puVar1;
}


