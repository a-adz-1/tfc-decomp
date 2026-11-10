// Apply_Results__FP11CBaseEntityP11CBasePlayerT1i  @ 0010bc50
void Apply_Results__FP11CBaseEntityP11CBasePlayerT1i
               (int *param_1,int *param_2,int *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piStack_18;
  
  iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
  if (iVar3 == 0) {
    param_2[0x100] = param_2[0x100] | param_1[0x100];
  }
  if (((param_2 == param_3) && (param_1[0xc6] != 0)) && (0 < param_2[0x48])) {
    TeamFortress_TeamIncreaseScore__Fii(param_2[0x48],param_1[0xc6]);
  }
  if (param_4 != 0) {
    iVar3 = (**(code **)(param_2[0x115] + 0x8c))(param_2);
    if (iVar3 != 0) {
      iVar3 = *param_1;
      fVar1 = *(float *)(iVar3 + 0x160);
      if (0x3f < (byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        (**(code **)(param_2[0x115] + 0x3c))(param_2,fVar1,0);
        iVar3 = *param_1;
      }
      if (*(float *)(iVar3 + 0x160) < 0.0) {
        (**(code **)(param_2[0x115] + 0x38))
                  (param_2,iVar3,iVar3,-*(float *)(iVar3 + 0x160),0x8001000);
      }
    }
    iVar3 = (**(code **)(param_2[0x115] + 0x8c))(param_2);
    if (iVar3 != 0) {
      iVar3 = *param_1;
      fVar1 = *(float *)(iVar3 + 0x1b8);
      if ((byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
        if (0.0 < *(float *)(iVar3 + 0x1bc)) {
          *(int *)(*param_2 + 0x1b8) = param_2[0x3b];
          iVar3 = *param_1;
        }
      }
      else {
        *(float *)(*param_2 + 0x1b8) = fVar1;
        iVar3 = *param_1;
      }
      *(float *)(*param_2 + 0x1bc) = *(float *)(*param_2 + 0x1bc) + *(float *)(iVar3 + 0x1bc);
      if (0 < param_1[0xe]) {
        param_2[0xe] = param_1[0xe];
      }
      GiveTFAmmo__11CBasePlayeriiii(param_2,param_1[0x33],param_1[0x35],param_1[0x39],param_1[0x37])
      ;
      param_2[0x2f] = param_2[0x2f] + param_1[0x2f];
      iVar3 = param_1[0x31];
      iVar2 = param_2[0x31];
      param_2[0x31] = iVar3 + iVar2;
      if (param_2[0x32] < iVar3 + iVar2) {
        param_2[0x31] = param_2[0x32];
      }
      if (param_2[0x13] != 0) {
        param_2[0x11] = param_2[0x11] + param_1[0x11];
      }
      if (param_2[0x14] != 0) {
        param_2[0x12] = param_2[0x12] + param_1[0x12];
      }
      if (((param_2[0x21] & 1U) != 0) &&
         ((((param_2[0x24] == 1 && (param_2[0x11] < 1)) && (param_1[0x11] < 0)) ||
          (((param_2[0x24] == 2 && (param_2[0x12] < 1)) && (param_1[0x12] < 0)))))) {
        param_2[0x21] = param_2[0x21] & 0xfffffbfe;
        param_2[0x20] = 1;
      }
      if (0.0 < (float)param_1[0x10b]) {
        *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x10;
        param_2[0x10b] = (int)(*gpGlobals + (float)param_1[0x10b]);
        iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
        if (iVar3 == 0) {
          *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 0x20;
          param_2[0x10b] = (int)(*gpGlobals + 666.0);
        }
        *(undefined4 *)(*param_2 + 0x15c) = 0;
      }
      if (0.0 < (float)param_1[0x10c]) {
        *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 8;
        param_2[0x10c] = (int)(*gpGlobals + (float)param_1[0x10c]);
        iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
        if (iVar3 == 0) {
          *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 0x40;
          param_2[0x10c] = (int)(*gpGlobals + 666.0);
        }
        *(undefined4 *)(*param_2 + 0x15c) = 0;
      }
      if (0.0 < (float)param_1[0x10d]) {
        *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x40;
        param_2[0x10d] = (int)(*gpGlobals + (float)param_1[0x10d]);
        iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
        if (iVar3 == 0) {
          *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 0x80;
          param_2[0x10d] = (int)(*gpGlobals + 666.0);
        }
        *(undefined4 *)(*param_2 + 0x15c) = 0;
      }
      if (0.0 < (float)param_1[0x10e]) {
        *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x20;
        param_2[0x10e] = (int)(*gpGlobals + (float)param_1[0x10e]);
        iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
        if (iVar3 == 0) {
          *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) | 1;
          param_2[0x10e] = (int)(*gpGlobals + 666.0);
        }
      }
    }
    param_2[0x49] = param_2[0x49] + param_1[0x49];
    fVar1 = *(float *)(*param_1 + 0x164);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      TF_AddFrags__11CBasePlayeri(param_2,(int)ROUND(fVar1));
    }
    TeamFortress_CheckClassStats__11CBasePlayer(param_2);
  }
  if ((*(int *)(*param_2 + 0x20c) == 8) && ((*(byte *)(param_1 + 0x8c) & 0x10) != 0)) {
    param_2[99] = (int)(*gpGlobals + 10.0);
    Spy_RemoveDisguise__11CBasePlayer(param_2);
  }
  if ((param_1[0x22] != 0) &&
     (iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal"), iVar3 != 0))
  {
    iVar3 = param_1[0x22];
    piVar5 = (int *)0x0;
    do {
      piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
      if (piVar5 == (int *)0x0) {
        (*DAT_0019f794)(1,"Could not find an item with a goal_no of %d.\n",iVar3);
        piVar5 = (int *)0x0;
        break;
      }
    } while (piVar5[0x84] != iVar3);
    if ((piVar5 != (int *)0x0) && (piVar5 != param_1)) {
      tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0(piVar5,param_2,param_1);
    }
  }
  iVar3 = param_1[199];
  if (iVar3 != 0) {
    piVar5 = (int *)0x0;
    do {
      piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
      if (piVar5 == (int *)0x0) {
        (*DAT_0019f794)(1,"Could not find an item with a goal_no of %d.\n",iVar3);
        piVar5 = (int *)0x0;
        break;
      }
    } while (piVar5[0x84] != iVar3);
    if (*(int *)(*piVar5 + 0x198) == *(int *)(*param_2 + 0x208)) {
      tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar5,param_2,1);
    }
  }
  if (param_1[0xac] != 0) {
    piStack_18 = (int *)0x0;
    piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"item_tfgoal");
    while (piVar5 != (int *)0x0) {
      if ((piVar5[0x85] == param_1[0xac]) &&
         (*(int *)(*piVar5 + 0x198) == *(int *)(*param_2 + 0x208))) {
        piStack_18 = piVar5;
      }
      piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"item_tfgoal");
      if (piStack_18 != (int *)0x0) {
        tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piStack_18,param_2,1);
        piStack_18 = (int *)0x0;
      }
    }
  }
  DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(param_2,param_1);
  uVar4 = param_1[0x8c];
  if ((uVar4 & 0x40) != 0) {
    param_2[0x36a] = 1;
    param_2[0x36b] = 1;
    Engineer_RemoveBuildings__11CBasePlayer(param_2);
    uVar4 = param_1[0x8c];
  }
  if (((uVar4 & 0x20) != 0) && (iVar3 = (**(code **)(param_2[0x115] + 0x8c))(param_2), iVar3 != 0))
  {
    ForceRespawn__11CBasePlayer(param_2);
  }
  if ((param_1[0xa6] != 0) && (param_2[0xa6] == 0)) {
    param_2[0xa6] = param_1[0xa6];
    param_2[0xa7] = param_1[0xa7];
    param_2[0xa8] = param_1[0xa8];
    param_2[0xa9] = param_1[0xa9];
    TeamFortress_SetSkin__11CBasePlayer(param_2);
  }
  return;
}


