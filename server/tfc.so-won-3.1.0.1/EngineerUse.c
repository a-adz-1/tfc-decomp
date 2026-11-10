// EngineerUse__11CBaseEntityP11CBasePlayer  @ 00100094
undefined4 EngineerUse__11CBaseEntityP11CBasePlayer(void)

{
  return 0;
}


// EngineerUse__11CBasePlayerP11CBasePlayer  @ 000d7420
undefined4 EngineerUse__11CBasePlayerP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar1 = *(float *)(*param_1 + 0x1b8);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(int *)(*param_1 + 0x1b8) = param_1[0x3b];
  }
  iVar4 = 10;
  if (param_2[0x37] < 0xb) {
    iVar4 = param_2[0x37];
  }
  iVar3 = iVar4 * 5;
  fVar1 = (float)param_1[0x3c] - *(float *)(*param_1 + 0x1bc);
  if (fVar1 < (float)iVar3) {
    iVar3 = (int)ROUND(fVar1);
    iVar4 = (int)ROUND(ROUND((double)iVar3 * 0.25));
  }
  if (0 < iVar3) {
    *(float *)(*param_1 + 0x1bc) = (float)iVar3 + *(float *)(*param_1 + 0x1bc);
    fVar1 = *(float *)(*param_1 + 0x1bc);
    fVar2 = (float)param_1[0x3c];
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      *(int *)(*param_1 + 0x1bc) = param_1[0x3c];
    }
    param_2[0x37] = param_2[0x37] - iVar4;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),1,"items/r_item2.wav",0x3f800000,0x3f4ccccd,0,100);
  }
  return 1;
}


// EngineerUse__12CTFDispenserP11CBasePlayer  @ 000928e8
undefined4 EngineerUse__12CTFDispenserP11CBasePlayer(int *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  float local_14;
  
  param_1[0x188] = (int)(*gpGlobals + 3.0);
  local_14 = (*(float *)(*param_1 + 0x1b0) - *(float *)(*param_1 + 0x160)) * 0.2;
  if ((byte)(0.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 0x40) {
    iVar7 = param_2[0x33];
    if (0x28 < iVar7) {
      iVar7 = 0x28;
    }
    if (iVar7 < 400 - param_1[0x33]) {
      fVar1 = 40.0;
      if ((int)param_2[0x33] < 0x29) {
        fVar1 = (float)(int)param_2[0x33];
      }
    }
    else {
      fVar1 = (float)(400 - param_1[0x33]);
    }
    param_2[0x33] = (int)ROUND((float)(int)param_2[0x33] - fVar1);
    param_1[0x33] = (int)ROUND(fVar1 + (float)param_1[0x33]);
    iVar7 = param_2[0x35];
    if (0x28 < iVar7) {
      iVar7 = 0x28;
    }
    if (iVar7 < 600 - param_1[0x35]) {
      fVar2 = 40.0;
      if ((int)param_2[0x35] < 0x29) {
        fVar2 = (float)(int)param_2[0x35];
      }
    }
    else {
      fVar2 = (float)(600 - param_1[0x35]);
    }
    param_2[0x35] = (int)ROUND((float)(int)param_2[0x35] - fVar2);
    param_1[0x35] = (int)ROUND(fVar2 + (float)param_1[0x35]);
    iVar7 = param_2[0x39];
    if (10 < iVar7) {
      iVar7 = 10;
    }
    if (iVar7 < 300 - param_1[0x39]) {
      fVar3 = 10.0;
      if ((int)param_2[0x39] < 0xb) {
        fVar3 = (float)(int)param_2[0x39];
      }
    }
    else {
      fVar3 = (float)(300 - param_1[0x39]);
    }
    param_2[0x39] = (int)ROUND((float)(int)param_2[0x39] - fVar3);
    param_1[0x39] = (int)ROUND(fVar3 + (float)param_1[0x39]);
    iVar7 = param_2[0x37];
    if (0x28 < iVar7) {
      iVar7 = 0x28;
    }
    if (iVar7 < 400 - param_1[0x37]) {
      fVar4 = 40.0;
      if ((int)param_2[0x37] < 0x29) {
        fVar4 = (float)(int)param_2[0x37];
      }
    }
    else {
      fVar4 = (float)(400 - param_1[0x37]);
    }
    param_2[0x37] = (int)ROUND((float)(int)param_2[0x37] - fVar4);
    param_1[0x37] = (int)ROUND(fVar4 + (float)param_1[0x37]);
    if ((int)ROUND(fVar4 + (float)(int)ROUND(fVar3 + (float)(int)ROUND(fVar2 + (float)(int)ROUND(
                                                  fVar1 + 0.0)))) < 1) {
      pcVar5 = "#Dispenser_AmmoNoMore";
    }
    else {
      pcVar5 = "#Menu_AmmoDisp";
    }
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,pcVar5,0,0,0,0);
    uVar6 = UTIL_dtos4__Fi(param_1[0x37]);
    uVar6 = UTIL_dtos3__Fi((int)ROUND(*(float *)(*param_1 + 0x1bc)),uVar6);
    uVar6 = UTIL_dtos2__Fi(param_1[0x39],uVar6);
    uVar6 = UTIL_dtos1__Fi((int)ROUND(*(float *)(*param_1 + 0x160)),uVar6);
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Dispenser_has",uVar6);
  }
  else {
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Menu_RepairDisp",0,0,0,0);
    if ((float)(int)param_2[0x37] < local_14) {
      local_14 = (float)(int)param_2[0x37];
    }
    param_2[0x37] = (int)ROUND((float)(int)param_2[0x37] - local_14);
    *(float *)(*param_1 + 0x160) = local_14 * 5.0 + *(float *)(*param_1 + 0x160);
  }
  return 1;
}


// EngineerUse__12CTFSentrygunP11CBasePlayer  @ 000dff1c
undefined4 EngineerUse__12CTFSentrygunP11CBasePlayer(int *param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((param_1[0x23] < 3) && (0x81 < (int)param_2[0x37])) {
    param_2[0x37] = param_2[0x37] + -0x82;
    uVar4 = UTIL_dtos1__Fi(param_1[0x23] + 1,0,0,0);
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Sentry_upgrade",uVar4);
    Upgrade__12CTFSentrygun(param_1);
  }
  else {
    iVar5 = *param_1;
    if (*(float *)(iVar5 + 0x160) < *(float *)(iVar5 + 0x1b0)) {
      iVar5 = (int)ROUND(ROUND((*(float *)(iVar5 + 0x1b0) - *(float *)(iVar5 + 0x160)) * 0.2));
      if ((int)param_2[0x37] < iVar5) {
        iVar5 = param_2[0x37];
      }
      if (0 < iVar5) {
        param_2[0x37] = param_2[0x37] - iVar5;
        iVar2 = *param_1;
        fVar3 = (float)(iVar5 * 5) + *(float *)(iVar2 + 0x160);
        fVar1 = *(float *)(iVar2 + 0x1b0);
        if (0x3f < (byte)((fVar1 < fVar3 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar3)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar3) << 0xe) >> 8)) - 1)) {
          fVar1 = fVar3;
        }
        *(float *)(iVar2 + 0x160) = fVar1;
        ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Sentry_repair",0,0,0,0);
        return 1;
      }
    }
    if ((param_1[0x33] < param_1[0x30]) && (0 < (int)param_2[0x33])) {
      iVar5 = 0x28;
      if ((int)param_2[0x33] < 0x28) {
        iVar5 = param_2[0x33];
      }
      if (param_1[0x30] - param_1[0x33] < iVar5) {
        iVar5 = param_1[0x30] - param_1[0x33];
      }
      param_2[0x33] = param_2[0x33] - iVar5;
      param_1[0x33] = param_1[0x33] + iVar5;
      ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Sentry_inshells",0,0,0,0);
    }
    if (((param_1[0x39] < param_1[0x38]) && (param_1[0x23] == 3)) && (0 < (int)param_2[0x39])) {
      iVar5 = 0x14;
      if ((int)param_2[0x39] < 0x14) {
        iVar5 = param_2[0x39];
      }
      if (param_1[0x38] - param_1[0x39] < iVar5) {
        iVar5 = param_1[0x38] - param_1[0x39];
      }
      param_2[0x39] = param_2[0x39] - iVar5;
      param_1[0x39] = param_1[0x39] + iVar5;
      ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Sentry_inrockets",0,0,0,0);
    }
  }
  return 1;
}


