// Apply_Results__FP11CBaseEntityP11CBasePlayerT1i  @ 0010a080
void Apply_Results__FP11CBaseEntityP11CBasePlayerT1i
               (int *param_1,int *param_2,int *param_3,int param_4)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  iVar4 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal");
  if (iVar4 == 0) {
    param_2[0xdd] = param_2[0xdd] | param_1[0xdd];
  }
  if (((param_2 == param_3) && (param_1[0xbf] != 0)) && (0 < param_2[0x48])) {
    TeamFortress_TeamIncreaseScore__Fii(param_2[0x48],param_1[0xbf]);
    TeamFortress_TeamShowScores__FiP11CBasePlayer(0,0);
  }
  if (param_4 == 0) goto LAB_0010a4c2;
  iVar4 = (**(code **)(param_2[0xf2] + 0x88))(param_2);
  if (iVar4 != 0) {
    fVar1 = *(float *)(*param_1 + 0x140);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      (**(code **)(param_2[0xf2] + 0x38))(param_2,*(undefined4 *)(*param_1 + 0x140),0);
    }
    iVar4 = *param_1;
    if (*(float *)(iVar4 + 0x140) < 0.0) {
      (**(code **)(param_2[0xf2] + 0x34))
                (param_2,iVar4,iVar4,0.0 - *(float *)(iVar4 + 0x140),0x8001000);
    }
  }
  iVar4 = (**(code **)(param_2[0xf2] + 0x88))(param_2);
  if (iVar4 != 0) {
    fVar1 = *(float *)(*param_1 + 0x198);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      iVar4 = *param_2;
LAB_0010a1e1:
      *(float *)(iVar4 + 0x198) = fVar1;
    }
    else {
      fVar1 = *(float *)(*param_1 + 0x19c);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        iVar4 = *param_2;
        fVar1 = (float)param_2[0x3b];
        goto LAB_0010a1e1;
      }
    }
    *(float *)(*param_2 + 0x19c) = *(float *)(*param_2 + 0x19c) + *(float *)(*param_1 + 0x19c);
    if (0 < param_1[0xf]) {
      param_2[0xf] = param_1[0xf];
    }
    GiveTFAmmo__11CBasePlayeriiii(param_2,param_1[0x33],param_1[0x35],param_1[0x39],param_1[0x37]);
    param_2[0x2f] = param_2[0x2f] + param_1[0x2f];
    iVar4 = param_1[0x31];
    iVar2 = param_2[0x31];
    param_2[0x31] = iVar4 + iVar2;
    if (param_2[0x32] < iVar4 + iVar2) {
      param_2[0x31] = param_2[0x32];
    }
    if (param_2[0x14] != 0) {
      param_2[0x12] = param_2[0x12] + param_1[0x12];
    }
    if (param_2[0x15] != 0) {
      param_2[0x13] = param_2[0x13] + param_1[0x13];
    }
    if (((*(byte *)(param_2 + 0x22) & 1) != 0) && ((param_2[0x13] < 1 || (param_2[0x12] < 1)))) {
      *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) & 0xfe;
      *(byte *)((int)param_2 + 0x89) = *(byte *)((int)param_2 + 0x89) & 0xfb;
      param_2[0x21] = 1;
    }
    fVar1 = (float)param_1[0xe8];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 0x10;
      pfVar3 = gpGlobals;
      param_2[0xe8] = (int)(*gpGlobals + (float)param_1[0xe8]);
      iVar4 = strcmp((char *)(*(int *)*param_1 + (int)pfVar3[0x26]),"item_tfgoal");
      if (iVar4 == 0) {
        *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) | 0x20;
        param_2[0xe8] = (int)(*gpGlobals + 666.0);
      }
    }
    fVar1 = (float)param_1[0xe9];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 8;
      pfVar3 = gpGlobals;
      param_2[0xe9] = (int)(*gpGlobals + (float)param_1[0xe9]);
      iVar4 = strcmp((char *)(*(int *)*param_1 + (int)pfVar3[0x26]),"item_tfgoal");
      if (iVar4 == 0) {
        *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) | 0x40;
        param_2[0xe9] = (int)(*gpGlobals + 666.0);
      }
    }
    fVar1 = (float)param_1[0xea];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 0x40;
      pfVar3 = gpGlobals;
      param_2[0xea] = (int)(*gpGlobals + (float)param_1[0xea]);
      iVar4 = strcmp((char *)(*(int *)*param_1 + (int)pfVar3[0x26]),"item_tfgoal");
      if (iVar4 == 0) {
        *(byte *)(param_2 + 0x22) = *(byte *)(param_2 + 0x22) | 0x80;
        param_2[0xea] = (int)(*gpGlobals + 666.0);
      }
    }
    fVar1 = (float)param_1[0xeb];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 0x20;
      pfVar3 = gpGlobals;
      param_2[0xeb] = (int)(*gpGlobals + (float)param_1[0xeb]);
      iVar4 = strcmp((char *)(*(int *)*param_1 + (int)pfVar3[0x26]),"item_tfgoal");
      if (iVar4 == 0) {
        *(byte *)((int)param_2 + 0x89) = *(byte *)((int)param_2 + 0x89) | 1;
        param_2[0xeb] = (int)(*gpGlobals + 666.0);
      }
    }
  }
  param_2[0x49] = param_2[0x49] + param_1[0x49];
  fVar1 = *(float *)(*param_1 + 0x144);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    TF_AddFrags__11CBasePlayeri(param_2,(int)ROUND(fVar1));
  }
  TeamFortress_CheckClassStats__11CBasePlayer(param_2);
LAB_0010a4c2:
  if ((param_2[0xb] == 8) && ((*(byte *)(param_1 + 0x8a) & 0x10) != 0)) {
    param_2[99] = (int)(*gpGlobals + 10.0);
    Spy_RemoveDisguise__11CBasePlayer(param_2);
  }
  if ((((param_1[0x23] != 0) &&
       (iVar4 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal"), iVar4 != 0)
       ) && (piVar5 = (int *)Finditem__Fi(param_1[0x23]), piVar5 != (int *)0x0)) &&
     (piVar5 != param_1)) {
    tfgoalitem_GiveToPlayer__FP11CBaseEntityP11CBasePlayerT0(piVar5,param_2,param_1);
  }
  if ((param_1[0xc0] != 0) &&
     (piVar5 = (int *)Finditem__Fi(param_1[0xc0]),
     *(int *)(*piVar5 + 0x178) == *(int *)(*param_2 + 0x1e8))) {
    tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar5,param_2,1);
  }
  if (param_1[0xa6] != 0) {
    piVar5 = (int *)0x0;
    piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"item_tfgoal");
    while (piVar6 != (int *)0x0) {
      if ((piVar6[0x85] == param_1[0xa6]) &&
         (*(int *)(*piVar6 + 0x178) == *(int *)(*param_2 + 0x1e8))) {
        piVar5 = piVar6;
      }
      piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"item_tfgoal");
      if (piVar5 != (int *)0x0) {
        tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar5,param_2,1);
        piVar5 = (int *)0x0;
      }
    }
  }
  DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(param_2,param_1);
  if (((*(byte *)(param_1 + 0x8a) & 0x20) != 0) &&
     (iVar4 = (**(code **)(param_2[0xf2] + 0x88))(param_2), iVar4 != 0)) {
    ForceRespawn__11CBasePlayer(param_2);
  }
  return;
}


