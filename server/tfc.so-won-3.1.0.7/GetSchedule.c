// GetSchedule__12CBaseMonster  @ 000e79d4
undefined1 * GetSchedule__12CBaseMonster(undefined4 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  longdouble lVar4;
  longdouble lVar5;
  undefined4 uVar6;
  
  switch(param_1[0x159]) {
  case 0:
    pcVar3 = "MONSTERSTATE IS NONE!\n";
    goto LAB_000e7cfc;
  case 1:
    if ((*(byte *)((int)param_1 + 0x4ea) & 2) == 0) {
      iVar1 = FRouteClear__12CBaseMonster(param_1);
      if (iVar1 == 0) {
        iVar1 = param_1[0x111];
        uVar6 = 2;
      }
      else {
        iVar1 = param_1[0x111];
        uVar6 = 1;
      }
      break;
    }
    goto LAB_000e7b05;
  case 2:
    if ((*(byte *)((int)param_1 + 0x4ea) & 0x10) != 0) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x13b,0);
      iVar1 = GetEnemy__12CBaseMonster(param_1);
      if (iVar1 != 0) {
        *(byte *)((int)param_1 + 0x4ea) = *(byte *)((int)param_1 + 0x4ea) & 0xef;
        puVar2 = (undefined1 *)(**(code **)(param_1[0x111] + 0x178))(param_1);
        return puVar2;
      }
      SetState__12CBaseMonster12MONSTERSTATE(param_1,3);
      puVar2 = (undefined1 *)(**(code **)(param_1[0x111] + 0x178))(param_1);
      return puVar2;
    }
    if ((*(byte *)((int)param_1 + 0x4ea) & 1) != 0) {
      iVar1 = param_1[0x111];
      uVar6 = 3;
      break;
    }
    if (((*(byte *)((int)param_1 + 0x4e9) & 1) != 0) && ((*(byte *)(param_1 + 0x18b) & 0x40) == 0))
    {
      iVar1 = param_1[0x111];
      uVar6 = 0x11;
      break;
    }
    if ((*(byte *)(param_1 + 0x13a) & 0x10) == 0) {
      if ((*(byte *)(param_1 + 0x13a) & 0x20) == 0) {
LAB_000e7c5d:
        iVar1 = param_1[0x111];
        uVar6 = 10;
        break;
      }
    }
    else {
      if ((*(byte *)((int)param_1 + 0x4e9) & 4) != 0) {
        iVar1 = param_1[0x111];
        uVar6 = 0x18;
        break;
      }
      if ((*(byte *)((int)param_1 + 0x4e9) & 0x10) != 0) {
        iVar1 = param_1[0x111];
        uVar6 = 0x19;
        break;
      }
      if ((*(byte *)((int)param_1 + 0x4e9) & 8) != 0) {
        iVar1 = param_1[0x111];
        uVar6 = 0x16;
        break;
      }
      if ((*(byte *)((int)param_1 + 0x4e9) & 0x20) != 0) {
        iVar1 = param_1[0x111];
        uVar6 = 0x17;
        break;
      }
      if ((*(byte *)((int)param_1 + 0x4e9) & 0xc) != 0) {
        iVar1 = FacingIdeal__12CBaseMonster(param_1);
        if (iVar1 != 0) {
          pcVar3 = "No suitable combat schedule!\n";
          goto LAB_000e7cfc;
        }
        goto LAB_000e7c5d;
      }
    }
    iVar1 = param_1[0x111];
    uVar6 = 0xc;
    break;
  case 3:
    if (((*(byte *)((int)param_1 + 0x4ea) & 0x10) != 0) &&
       (iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x41), iVar1 != -1)) {
      iVar1 = param_1[0x111];
      uVar6 = 0xe;
      break;
    }
    if ((*(byte *)((int)param_1 + 0x4e9) & 3) != 0) {
      lVar4 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
      lVar4 = ABS(lVar4);
      lVar5 = (longdouble)60.0 * ((longdouble)1.0 - (longdouble)(float)param_1[0x153]);
      if ((byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1) < 0x40) {
        iVar1 = param_1[0x111];
        uVar6 = 6;
      }
      else {
        iVar1 = param_1[0x111];
        uVar6 = 0x14;
      }
      break;
    }
    if ((*(byte *)((int)param_1 + 0x4ea) & 2) == 0) {
      iVar1 = param_1[0x111];
      uVar6 = 8;
      break;
    }
LAB_000e7b05:
    iVar1 = param_1[0x111];
    uVar6 = 5;
    break;
  default:
    pcVar3 = "Invalid State for GetSchedule!\n";
LAB_000e7cfc:
    (*DAT_001c1114)(2,pcVar3);
    return slError;
  case 5:
    iVar1 = param_1[0x111];
    uVar6 = 0x26;
    break;
  case 6:
    if (param_1[0x1a2] == 0) {
      (*DAT_001c1114)(2,"Script failed for %s\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98));
      CineCleanup__12CBaseMonster(param_1);
      puVar2 = (undefined1 *)(**(code **)(param_1[0x111] + 0x174))(param_1,1);
      return puVar2;
    }
    iVar1 = param_1[0x111];
    uVar6 = 0x28;
    break;
  case 8:
    iVar1 = param_1[0x111];
    uVar6 = 0x21;
  }
  puVar2 = (undefined1 *)(**(code **)(iVar1 + 0x174))(param_1,uVar6);
  return puVar2;
}


