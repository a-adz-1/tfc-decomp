// GetScheduleOfType__12CBaseMonsteri  @ 0009035c
undefined1 * GetScheduleOfType__12CBaseMonsteri(undefined4 *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  switch(param_2) {
  case 1:
    iVar2 = (*DAT_001a7fa8)(0,0xe);
    if ((iVar2 == 0) && (iVar2 = (**(code **)(param_1[0xf5] + 0x1c4))(param_1), iVar2 != 0)) {
      puVar1 = slActiveIdle;
    }
    else {
      puVar1 = slIdleStand;
    }
    break;
  case 2:
    puVar1 = slIdleWalk;
    break;
  case 3:
    puVar1 = slWakeAngry;
    break;
  default:
    (*DAT_001a7f34)(1,"GetScheduleOfType()\nNo CASE for Schedule Type %d!\n",param_2);
    puVar1 = slIdleStand;
    break;
  case 5:
    puVar1 = slAlertFace;
    break;
  case 6:
    puVar1 = slAlertSmallFlinch;
    break;
  case 8:
    puVar1 = slAlertStand;
    break;
  case 9:
    puVar1 = slInvestigateSound;
    break;
  case 10:
    puVar1 = slCombatFace;
    break;
  case 0xb:
    puVar1 = slCombatStand;
    break;
  case 0xc:
    puVar1 = slChaseEnemy;
    break;
  case 0xd:
  case 0x29:
    puVar1 = slFail;
    break;
  case 0xe:
    puVar1 = slVictoryDance;
    break;
  case 0x11:
    puVar1 = slSmallFlinch;
    break;
  case 0x12:
    puVar1 = slTakeCoverFromEnemy;
    break;
  case 0x13:
    puVar1 = slTakeCoverFromBestSound;
    break;
  case 0x14:
    puVar1 = slTakeCoverFromOrigin;
    break;
  case 0x15:
    puVar1 = slCower;
    break;
  case 0x16:
    puVar1 = slPrimaryMeleeAttack;
    break;
  case 0x17:
    puVar1 = slSecondaryMeleeAttack;
    break;
  case 0x18:
    puVar1 = slRangeAttack1;
    break;
  case 0x19:
    puVar1 = slRangeAttack2;
    break;
  case 0x1a:
    puVar1 = slSpecialAttack1;
    break;
  case 0x1b:
    puVar1 = slSpecialAttack2;
    break;
  case 0x1c:
    puVar1 = slStandoff;
    break;
  case 0x1d:
    puVar1 = slArmWeapon;
    break;
  case 0x1e:
    puVar1 = slReload;
    break;
  case 0x20:
    puVar1 = slAmbush;
    break;
  case 0x21:
    puVar1 = slDie;
    break;
  case 0x22:
    puVar1 = slIdleTrigger;
    break;
  case 0x26:
    puVar1 = slBarnacleVictimGrab;
    break;
  case 0x27:
    puVar1 = slBarnacleVictimChomp;
    break;
  case 0x28:
    if (param_1[0x186] == 0) {
      (*DAT_001a7f34)(2,"Script failed for %s\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      CineCleanup__12CBaseMonster(param_1);
      puVar1 = (undefined1 *)(**(code **)(param_1[0xf5] + 0x16c))(param_1,1);
    }
    else {
      switch(*(undefined4 *)(param_1[0x186] + 0x628)) {
      case 0:
      case 4:
        puVar1 = slWaitScript;
        break;
      case 1:
        puVar1 = slWalkToScript;
        break;
      case 2:
        puVar1 = slRunToScript;
        break;
      default:
        puVar1 = (undefined1 *)0x0;
        break;
      case 5:
        puVar1 = slFaceScript;
      }
    }
  }
  return puVar1;
}


// GetScheduleOfType__12CTalkMonsteri  @ 000e985c
undefined1 * GetScheduleOfType__12CTalkMonsteri(int *param_1,undefined4 param_2)

{
  float fVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  undefined1 *puVar5;
  longdouble lVar6;
  
  switch(param_2) {
  case 1:
    if ((*(byte *)(param_1 + 0x187) & 8) == 0) {
      return slIdleHello;
    }
    if ((*(byte *)(param_1 + 0x187) & 0x10) == 0) {
      fVar3 = *(float *)(*param_1 + 0x1b0) * 0.75;
      fVar1 = *(float *)(*param_1 + 0x160);
      if ((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) != 1) {
        iVar4 = param_1[0xf5];
        lVar6 = (longdouble)(*DAT_001a7fac)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
        (**(code **)(iVar4 + 0x180))(param_1,param_1[0x19a],(float)lVar6);
        *(byte *)(param_1 + 0x187) = *(byte *)(param_1 + 0x187) | 0x10;
        goto code_r0x000e9a8f;
      }
    }
    if ((*(byte *)(param_1 + 0x187) & 0x20) == 0) {
      fVar3 = *(float *)(*param_1 + 0x1b0) * 0.5;
      fVar1 = *(float *)(*param_1 + 0x160);
      if ((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) != 1) {
        iVar4 = param_1[0xf5];
        lVar6 = (longdouble)(*DAT_001a7fac)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
        (**(code **)(iVar4 + 0x180))(param_1,param_1[0x19b],(float)lVar6);
        *(byte *)(param_1 + 0x187) = *(byte *)(param_1 + 0x187) | 0x20;
code_r0x000e9a8f:
        return slIdleStand;
      }
    }
    iVar4 = FOkToSpeak__12CTalkMonster(param_1);
    if ((iVar4 != 0) && (iVar4 = (*DAT_001a7fa8)(0,param_1[0x188] * 2), iVar4 == 0)) {
      return slIdleSpeak;
    }
    iVar4 = IsTalking__12CTalkMonster(param_1);
    if (((iVar4 != 0) || ((*(byte *)((int)param_1 + 0x47a) & 0x20) == 0)) ||
       (iVar4 = (*DAT_001a7fa8)(0,6), iVar4 != 0)) {
      iVar4 = IsTalking__12CTalkMonster(param_1);
      if (iVar4 != 0) {
        return slTlkIdleEyecontact;
      }
      goto LAB_000e9c0c;
    }
    iVar4 = (*DAT_001a7f60)(1);
    if (iVar4 != 0) {
      UTIL_MakeVectors__FRC6Vector(iVar4 + 0xd0);
      bVar2 = false;
      fVar1 = *(float *)(iVar4 + 0x88) - *(float *)(*param_1 + 8);
      fVar3 = *(float *)(iVar4 + 0x8c) - *(float *)(*param_1 + 0xc);
      fVar1 = SQRT(fVar3 * fVar3 + fVar1 * fVar1);
      if (0x3f < (byte)((128.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 128.0) << 0xe) >> 8)) - 1)) {
        lVar6 = (longdouble)
                UTIL_DotPoints__FRC6VectorN20(iVar4 + 0x88,*param_1 + 8,gpGlobals + 0x28);
        bVar2 = (longdouble)(float)param_1[0x137] <= lVar6;
      }
      if (bVar2) {
        return slTlkIdleWatchClient + 0x14;
      }
      return slTlkIdleWatchClient;
    }
  default:
    puVar5 = (undefined1 *)GetScheduleOfType__12CBaseMonsteri(param_1,param_2);
    break;
  case 0xf:
    iVar4 = (*DAT_001a7fa8)(0,99);
    if (iVar4 < 2) {
      return slIdleSpeakWait;
    }
LAB_000e9c0c:
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


// GetScheduleOfType__13CSquadMonsteri  @ 000e6984
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


