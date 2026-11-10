// Apply_Results__FP11CBaseEntityP11CBasePlayerT1i  @ 000fb738
void Apply_Results__FP11CBaseEntityP11CBasePlayerT1i
               (int *param_1,int *param_2,int *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piStack_14;
  
  iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
  if (iVar3 == 0) {
    param_2[0xe0] = param_2[0xe0] | param_1[0xe0];
  }
  if (((param_2 == param_3) && (param_1[0xbf] != 0)) && (0 < param_2[0x48])) {
    TeamFortress_TeamIncreaseScore__Fii(param_2[0x48],param_1[0xbf]);
  }
  if (param_4 == 0) goto LAB_000fbc8f;
  iVar3 = (**(code **)(param_2[0xf5] + 0x88))(param_2);
  if (iVar3 != 0) {
    if (0.0 < *(float *)(*param_1 + 0x160)) {
      (**(code **)(param_2[0xf5] + 0x38))(param_2,*(undefined4 *)(*param_1 + 0x160),0);
    }
    iVar3 = *param_1;
    fVar1 = *(float *)(iVar3 + 0x160);
    if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
      (**(code **)(param_2[0xf5] + 0x34))(param_2,iVar3,iVar3,-*(float *)(iVar3 + 0x160),0x8001000);
    }
  }
  iVar3 = (**(code **)(param_2[0xf5] + 0x88))(param_2);
  if (iVar3 != 0) {
    fVar1 = *(float *)(*param_1 + 0x1b8);
    if (fVar1 <= 0.0) {
      if (0.0 < *(float *)(*param_1 + 0x1bc)) {
        iVar3 = *param_2;
        fVar1 = (float)param_2[0x3b];
        goto LAB_000fb8be;
      }
    }
    else {
      iVar3 = *param_2;
LAB_000fb8be:
      *(float *)(iVar3 + 0x1b8) = fVar1;
    }
    *(float *)(*param_2 + 0x1bc) = *(float *)(*param_2 + 0x1bc) + *(float *)(*param_1 + 0x1bc);
    if (0 < param_1[0xe]) {
      param_2[0xe] = param_1[0xe];
    }
    GiveTFAmmo__11CBasePlayeriiii(param_2,param_1[0x33],param_1[0x35],param_1[0x39],param_1[0x37]);
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
    if (((*(byte *)(param_2 + 0x21) & 1) != 0) &&
       ((((param_2[0x24] == 1 && (param_2[0x11] < 1)) && (param_1[0x11] < 0)) ||
        (((param_2[0x24] == 2 && (param_2[0x12] < 1)) && (param_1[0x12] < 0)))))) {
      *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xfe;
      *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) & 0xfb;
      param_2[0x20] = 1;
    }
    if (0.0 < (float)param_1[0xeb]) {
      *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x10;
      param_2[0xeb] = (int)(*gpGlobals + (float)param_1[0xeb]);
      iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
      if (iVar3 == 0) {
        *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 0x20;
        param_2[0xeb] = (int)(*gpGlobals + 666.0);
      }
      *(undefined4 *)(*param_2 + 0x15c) = 0;
    }
    if (0.0 < (float)param_1[0xec]) {
      *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 8;
      param_2[0xec] = (int)(*gpGlobals + (float)param_1[0xec]);
      iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
      if (iVar3 == 0) {
        *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 0x40;
        param_2[0xec] = (int)(*gpGlobals + 666.0);
      }
      *(undefined4 *)(*param_2 + 0x15c) = 0;
    }
    if (0.0 < (float)param_1[0xed]) {
      *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x40;
      param_2[0xed] = (int)(*gpGlobals + (float)param_1[0xed]);
      iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
      if (iVar3 == 0) {
        *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 0x80;
        param_2[0xed] = (int)(*gpGlobals + 666.0);
      }
      *(undefined4 *)(*param_2 + 0x15c) = 0;
    }
    if (0.0 < (float)param_1[0xee]) {
      *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 0x20;
      param_2[0xee] = (int)(*gpGlobals + (float)param_1[0xee]);
      iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
      if (iVar3 == 0) {
        *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) | 1;
        param_2[0xee] = (int)(*gpGlobals + 666.0);
      }
    }
  }
  param_2[0x49] = param_2[0x49] + param_1[0x49];
  fVar1 = *(float *)(*param_1 + 0x164);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    TF_AddFrags__11CBasePlayeri(param_2,(int)ROUND(fVar1));
  }
  TeamFortress_CheckClassStats__11CBasePlayer(param_2);
LAB_000fbc8f:
  if ((*(int *)(*param_2 + 0x20c) == 8) && ((*(byte *)(param_1 + 0x8a) & 0x10) != 0)) {
    param_2[99] = (int)(*gpGlobals + 10.0);
    Spy_RemoveDisguise__11CBasePlayer(param_2);
  }
  if ((((param_1[0x22] != 0) &&
       (iVar3 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal"), iVar3 != 0)
       ) && (piVar4 = (int *)Finditem__Fi(param_1[0x22]), piVar4 != (int *)0x0)) &&
     (piVar4 != param_1)) {
    tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0(piVar4,param_2,param_1);
  }
  if ((param_1[0xc0] != 0) &&
     (piVar4 = (int *)Finditem__Fi(param_1[0xc0]),
     *(int *)(*piVar4 + 0x198) == *(int *)(*param_2 + 0x208))) {
    tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar4,param_2,1);
  }
  if (param_1[0xa6] != 0) {
    piStack_14 = (int *)0x0;
    piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"item_tfgoal");
    while (piVar4 != (int *)0x0) {
      if ((piVar4[0x85] == param_1[0xa6]) &&
         (*(int *)(*piVar4 + 0x198) == *(int *)(*param_2 + 0x208))) {
        piStack_14 = piVar4;
      }
      piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"item_tfgoal");
      if (piStack_14 != (int *)0x0) {
        tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piStack_14,param_2,1);
        piStack_14 = (int *)0x0;
      }
    }
  }
  DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(param_2,param_1);
  if ((*(byte *)(param_1 + 0x8a) & 0x40) != 0) {
    param_2[0x343] = 1;
    param_2[0x344] = 1;
    Engineer_RemoveBuildings__11CBasePlayer(param_2);
  }
  if (((*(byte *)(param_1 + 0x8a) & 0x20) != 0) &&
     (iVar3 = (**(code **)(param_2[0xf5] + 0x88))(param_2), iVar3 != 0)) {
    ForceRespawn__11CBasePlayer(param_2);
  }
  return;
}


