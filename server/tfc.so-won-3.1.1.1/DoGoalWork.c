// DoGoalWork__FP11CBaseEntityP11CBasePlayer  @ 0010d308
void DoGoalWork__FP11CBaseEntityP11CBasePlayer(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  
  iVar3 = *(int *)(param_1 + 0x25c);
  if (iVar3 != 0) {
    iVar6 = 0;
    do {
      iVar6 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar6,"info_tfgoal");
      if (iVar6 == 0) {
        (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar3);
        iVar6 = 0;
        break;
      }
    } while (*(int *)(iVar6 + 0x210) != iVar3);
    if ((iVar6 != 0) &&
       (iVar3 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(iVar6,param_2,param_1),
       iVar3 != 0)) {
      if ((param_1 == iVar6) || (*(int *)(iVar6 + 0x27c) == 1)) {
        uVar8 = 1;
      }
      else if (param_1 == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(uint *)(param_1 + 0x230) & 2;
      }
      DoResults__FP11CBaseEntityP11CBasePlayeri(iVar6,param_2,uVar8);
    }
  }
  iVar3 = *(int *)(param_1 + 0x260);
  if (iVar3 != 0) {
    piVar7 = (int *)0x0;
    do {
      piVar7 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar7,"info_tfgoal");
      if (piVar7 == (int *)0x0) {
        (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar3);
        piVar7 = (int *)0x0;
        break;
      }
    } while (piVar7[0x84] != iVar3);
    if ((piVar7 != (int *)0x0) && (piVar7[0x86] == 1)) {
      iVar3 = (**(code **)(piVar7[0x115] + 0x2c))(piVar7);
      if (iVar3 != 0x81) {
        if (((*(byte *)((int)piVar7 + 0x229) & 0x20) == 0) ||
           ((iVar3 = (**(code **)(piVar7[0x115] + 0x2c))(piVar7), iVar3 != 0x80 &&
            (iVar3 = (**(code **)(piVar7[0x115] + 0x2c))(piVar7), iVar3 != 0x82)))) {
          *(undefined4 *)(*piVar7 + 0x10c) = 1;
        }
        else {
          *(undefined4 *)(*piVar7 + 0x10c) = 2;
        }
      }
      piVar7[0x86] = 2;
      if (*(char *)(*(int *)(*piVar7 + 0xb8) + (int)gpGlobals[0x26]) != '*') {
        pbVar1 = (byte *)(*piVar7 + 0x118);
        *pbVar1 = *pbVar1 & 0x7f;
      }
    }
  }
  iVar3 = *(int *)(param_1 + 0x268);
  if (iVar3 != 0) {
    piVar7 = (int *)0x0;
    do {
      piVar7 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar7,"info_tfgoal");
      if (piVar7 == (int *)0x0) {
        (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar3);
        piVar7 = (int *)0x0;
        break;
      }
    } while (piVar7[0x84] != iVar3);
    if ((piVar7 != (int *)0x0) && (piVar7[0x86] == 3)) {
      fVar2 = (float)piVar7[0x95];
      if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
        if (((*(byte *)((int)piVar7 + 0x229) & 0x20) == 0) ||
           (iVar3 = strcmp((char *)(*(int *)*piVar7 + (int)gpGlobals[0x26]),"item_tfgoal"),
           iVar3 != 0)) {
          *(undefined4 *)(*piVar7 + 0x10c) = 1;
        }
        else {
          *(undefined4 *)(*piVar7 + 0x10c) = 2;
        }
      }
      else {
        *(float *)(*piVar7 + 0x104) = *gpGlobals + fVar2;
      }
      piVar7[0x86] = 2;
      if (*(char *)(*(int *)(*piVar7 + 0xb8) + (int)gpGlobals[0x26]) != '*') {
        pbVar1 = (byte *)(*piVar7 + 0x118);
        *pbVar1 = *pbVar1 & 0x7f;
      }
    }
  }
  iVar3 = *(int *)(param_1 + 0x264);
  if (iVar3 != 0) {
    piVar7 = (int *)0x0;
    do {
      piVar7 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar7,"info_tfgoal");
      if (piVar7 == (int *)0x0) {
        (*DAT_0019f794)(1,"Could not find a goal with a goal_no of %d.\n",iVar3);
        piVar7 = (int *)0x0;
        break;
      }
    } while (piVar7[0x84] != iVar3);
    if (piVar7 != (int *)0x0) {
      *(undefined4 *)(*piVar7 + 0x10c) = 0;
      piVar7[0x86] = 3;
      *(byte *)(*piVar7 + 0x118) = *(byte *)(*piVar7 + 0x118) | 0x80;
    }
  }
  iVar3 = *(int *)(param_1 + 0x2b4);
  if (iVar3 != 0) {
    piVar7 = (int *)0x0;
    do {
      piVar7 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar7,"item_tfgoal");
      if (piVar7 == (int *)0x0) {
        (*DAT_0019f794)(1,"Could not find an item with a goal_no of %d.\n",iVar3);
        piVar7 = (int *)0x0;
        break;
      }
    } while (piVar7[0x84] != iVar3);
    if (piVar7 != (int *)0x0) {
      iVar3 = *(int *)(*piVar7 + 0x198);
      if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(undefined4 *)(iVar3 + 0x7c);
      }
      if (piVar7[0x86] == 1) {
        tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar7,uVar5,1);
      }
      piVar4 = (int *)CreateTimer__11CBaseEntityi(piVar7,100);
      piVar4[0x23] = 3;
      piVar4[3] = -0x10000;
      piVar4[4] = (int)ReturnItem__11CBaseEntity;
      *(float *)(*piVar4 + 0x104) = *gpGlobals + 0.1;
      *(undefined4 *)(*piVar7 + 0x10c) = 0;
      UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar7,*piVar7 + 8);
    }
  }
  iVar3 = *(int *)(param_1 + 0x2c0);
  if (iVar3 != 0) {
    iVar6 = 0;
    do {
      iVar6 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1(iVar6,"netname","info_player_teamspawn")
      ;
      if (iVar6 == 0) {
        (*DAT_0019f794)(1,"Could not find a Teamspawn with a goal_no of %d.\n",iVar3);
        iVar6 = 0;
        break;
      }
    } while (*(int *)(iVar6 + 0x210) != iVar3);
    if (iVar6 != 0) {
      *(undefined4 *)(iVar6 + 0x218) = 3;
    }
  }
  iVar3 = *(int *)(param_1 + 0x2c4);
  if (iVar3 != 0) {
    iVar6 = 0;
    do {
      iVar6 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1(iVar6,"netname","info_player_teamspawn")
      ;
      if (iVar6 == 0) {
        (*DAT_0019f794)(1,"Could not find a Teamspawn with a goal_no of %d.\n",iVar3);
        iVar6 = 0;
        break;
      }
    } while (*(int *)(iVar6 + 0x210) != iVar3);
    if ((iVar6 != 0) && (*(int *)(iVar6 + 0x218) == 3)) {
      *(undefined4 *)(iVar6 + 0x218) = 2;
    }
  }
  return;
}


