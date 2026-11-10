// EngineerUse__11CBaseEntityP11CBasePlayer  @ 00112838
undefined4 EngineerUse__11CBaseEntityP11CBasePlayer(void)

{
  return 0;
}


// EngineerUse__11CBasePlayerP11CBasePlayer  @ 000e28fc
undefined4 EngineerUse__11CBasePlayerP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x1b8)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x1b8) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(int *)(iVar2 + 0x1b8) = param_1[0x3b];
    iVar2 = *param_1;
  }
  iVar3 = 10;
  if (param_2[0x37] < 0xb) {
    iVar3 = param_2[0x37];
  }
  fVar1 = (float)param_1[0x3c] - *(float *)(iVar2 + 0x1bc);
  iVar2 = iVar3 * 5;
  if (fVar1 < (float)iVar2) {
    iVar2 = (int)ROUND(fVar1);
    iVar3 = (int)ROUND(ROUND((double)iVar2 * 0.25));
  }
  if (0 < iVar2) {
    *(float *)(*param_1 + 0x1bc) = *(float *)(*param_1 + 0x1bc) + (float)iVar2;
    if ((float)param_1[0x3c] < *(float *)(*param_1 + 0x1bc)) {
      *(int *)(*param_1 + 0x1bc) = param_1[0x3c];
    }
    param_2[0x37] = param_2[0x37] - iVar3;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x208),1,"items/r_item2.wav",0x3f800000,0x3f4ccccd,0,100);
  }
  return 1;
}


// EngineerUse__12CTFDispenserP11CBasePlayer  @ 0009c1dc
undefined4 EngineerUse__12CTFDispenserP11CBasePlayer(int *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  
  param_1[0x1a8] = (int)(*gpGlobals + 3.0);
  fVar1 = (*(float *)(*param_1 + 0x1b0) - *(float *)(*param_1 + 0x160)) * 0.2;
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    iVar5 = param_2[0x33];
    iVar7 = iVar5;
    if (0x28 < iVar5) {
      iVar7 = 0x28;
    }
    if (iVar7 < 400 - param_1[0x33]) {
      fVar1 = 40.0;
      if (iVar5 < 0x29) {
        fVar1 = (float)iVar5;
      }
    }
    else {
      fVar1 = (float)(400 - param_1[0x33]);
    }
    param_2[0x33] = (int)ROUND((float)iVar5 - fVar1);
    param_1[0x33] = (int)ROUND(fVar1 + (float)param_1[0x33]);
    iVar5 = param_2[0x35];
    iVar7 = iVar5;
    if (0x28 < iVar5) {
      iVar7 = 0x28;
    }
    if (iVar7 < 600 - param_1[0x35]) {
      fVar2 = 40.0;
      if (iVar5 < 0x29) {
        fVar2 = (float)iVar5;
      }
    }
    else {
      fVar2 = (float)(600 - param_1[0x35]);
    }
    param_2[0x35] = (int)ROUND((float)iVar5 - fVar2);
    param_1[0x35] = (int)ROUND(fVar2 + (float)param_1[0x35]);
    iVar5 = param_2[0x39];
    iVar7 = iVar5;
    if (10 < iVar5) {
      iVar7 = 10;
    }
    if (iVar7 < 300 - param_1[0x39]) {
      fVar3 = 10.0;
      if (iVar5 < 0xb) {
        fVar3 = (float)iVar5;
      }
    }
    else {
      fVar3 = (float)(300 - param_1[0x39]);
    }
    param_2[0x39] = (int)ROUND((float)iVar5 - fVar3);
    param_1[0x39] = (int)ROUND(fVar3 + (float)param_1[0x39]);
    iVar5 = param_2[0x37];
    iVar7 = iVar5;
    if (0x28 < iVar5) {
      iVar7 = 0x28;
    }
    if (iVar7 < 400 - param_1[0x37]) {
      fVar4 = 40.0;
      if (iVar5 < 0x29) {
        fVar4 = (float)iVar5;
      }
    }
    else {
      fVar4 = (float)(400 - param_1[0x37]);
    }
    param_2[0x37] = (int)ROUND((float)iVar5 - fVar4);
    param_1[0x37] = (int)ROUND(fVar4 + (float)param_1[0x37]);
    if ((int)ROUND(fVar4 + (float)(int)ROUND(fVar3 + (float)(int)ROUND(fVar2 + (float)(int)ROUND(
                                                  fVar1 + 0.0)))) < 1) {
      pcVar8 = "#Dispenser_AmmoNoMore";
    }
    else {
      pcVar8 = "#Menu_AmmoDisp";
    }
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,pcVar8,0,0,0,0);
    uVar6 = UTIL_dtos4__Fi(param_1[0x37]);
    uVar6 = UTIL_dtos3__Fi((int)ROUND(*(float *)(*param_1 + 0x1bc)),uVar6);
    uVar6 = UTIL_dtos2__Fi(param_1[0x39],uVar6);
    uVar6 = UTIL_dtos1__Fi((int)ROUND(*(float *)(*param_1 + 0x160)),uVar6);
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Dispenser_has",uVar6);
  }
  else {
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Menu_RepairDisp",0,0,0,0);
    fVar2 = (float)(int)param_2[0x37];
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar2;
    }
    param_2[0x37] = (int)ROUND(fVar2 - fVar1);
    *(float *)(*param_1 + 0x160) = *(float *)(*param_1 + 0x160) + fVar1 * 5.0;
  }
  return 1;
}


// EngineerUse__12CTFSentrygunP11CBasePlayer  @ 000edddc
undefined4 EngineerUse__12CTFSentrygunP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_50;
  
  if ((2 < param_1[0x23]) || (param_2[0x37] < 0x82)) {
    fVar1 = *(float *)(*param_1 + 0x160);
    fVar2 = *(float *)(*param_1 + 0x1b0);
    if (0x3f < (byte)((fVar2 < fVar1 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
      iVar6 = (int)ROUND(ROUND((fVar2 - fVar1) * 0.2));
      iVar8 = param_2[0x37];
      if (iVar8 < iVar6) {
        iVar6 = iVar8;
      }
      if (0 < iVar6) {
        param_2[0x37] = iVar8 - iVar6;
        iVar8 = *param_1;
        fVar2 = *(float *)(iVar8 + 0x160) + (float)(iVar6 * 5);
        fVar1 = *(float *)(iVar8 + 0x1b0);
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          fVar1 = fVar2;
        }
        *(float *)(iVar8 + 0x160) = fVar1;
        ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Sentry_repair",0,0,0,0);
        param_1 = param_1 + 0x51;
        piVar7 = (int *)__rf__7EHANDLE(param_1);
        iVar6 = *param_2;
        if (iVar6 == *piVar7) {
          if (param_2[0x48] == 0) {
            pcVar5 = "SPECTATOR";
          }
          else {
            pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
            iVar6 = *param_2;
          }
          uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(iVar6 + 0x208),pcVar5);
          uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Sentry_Repair\"\n",
                     *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar3);
          return 1;
        }
        iVar6 = __rf__7EHANDLE(param_1);
        if (*(int *)(iVar6 + 0x120) == 0) {
          pcVar5 = "SPECTATOR";
        }
        else {
          iVar6 = __rf__7EHANDLE(param_1);
          pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar6 + 0x120));
        }
        piVar7 = (int *)__rf__7EHANDLE(param_1,pcVar5);
        uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar7 + 0x208));
        piVar7 = (int *)__rf__7EHANDLE(param_1,uVar3);
        uVar3 = (*DAT_0019f864)(*(undefined4 *)(*piVar7 + 0x208));
        piVar7 = (int *)__rf__7EHANDLE(param_1,uVar3);
        if (param_2[0x48] == 0) {
          pcVar5 = "SPECTATOR";
        }
        else {
          pcVar5 = (char *)GetTeamName__Fi(param_2[0x48],
                                           *(int *)(*piVar7 + 0x1d0) + *(int *)(gpGlobals + 0x98));
        }
        uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
        uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%s><%s>\" triggered \"Sentry_Repair\" against \"%s<%i><%s><%s>\"\n",
                   *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar3);
        return 1;
      }
    }
    if ((param_1[0x33] < param_1[0x30]) && (iVar6 = param_2[0x33], 0 < iVar6)) {
      local_50 = 0x28;
      if (iVar6 < 0x28) {
        local_50 = iVar6;
      }
      iVar8 = param_1[0x30] - param_1[0x33];
      if (iVar8 < local_50) {
        local_50 = iVar8;
      }
      param_2[0x33] = iVar6 - local_50;
      param_1[0x33] = param_1[0x33] + local_50;
      ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Sentry_inshells",0,0,0,0);
    }
    if (param_1[0x38] <= param_1[0x39]) {
      return 1;
    }
    if (param_1[0x23] != 3) {
      return 1;
    }
    iVar6 = param_2[0x39];
    if (iVar6 < 1) {
      return 1;
    }
    local_50 = 0x14;
    if (iVar6 < 0x14) {
      local_50 = iVar6;
    }
    iVar8 = param_1[0x38] - param_1[0x39];
    if (iVar8 < local_50) {
      local_50 = iVar8;
    }
    param_2[0x39] = iVar6 - local_50;
    param_1[0x39] = param_1[0x39] + local_50;
    ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Sentry_inrockets",0,0,0,0);
    return 1;
  }
  param_2[0x37] = param_2[0x37] + -0x82;
  uVar3 = UTIL_dtos1__Fi(param_1[0x23] + 1,0,0,0);
  ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Sentry_upgrade",uVar3);
  if (param_1[0x23] == 1) {
    piVar7 = param_1 + 0x51;
    piVar4 = (int *)__rf__7EHANDLE(piVar7);
    iVar6 = *param_2;
    if (iVar6 != *piVar4) {
      iVar6 = __rf__7EHANDLE(piVar7);
      if (*(int *)(iVar6 + 0x120) == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        iVar6 = __rf__7EHANDLE(piVar7);
        pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar6 + 0x120));
      }
      piVar4 = (int *)__rf__7EHANDLE(piVar7,pcVar5);
      uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208));
      piVar4 = (int *)__rf__7EHANDLE(piVar7,uVar3);
      uVar3 = (*DAT_0019f864)(*(undefined4 *)(*piVar4 + 0x208));
      piVar7 = (int *)__rf__7EHANDLE(piVar7,uVar3);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48],
                                         *(int *)(*piVar7 + 0x1d0) + *(int *)(gpGlobals + 0x98));
      }
      uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
      iVar6 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
      pcVar5 = 
      "\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_2\" against \"%s<%i><%s><%s>\"\n";
LAB_000ee251:
      UTIL_LogPrintf__FPce(pcVar5,iVar6,uVar3);
      goto LAB_000ee25a;
    }
    if (param_2[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      iVar6 = *param_2;
    }
    uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(iVar6 + 0x208),pcVar5);
    uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
    iVar6 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar5 = "\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_2\"\n";
  }
  else {
    if (param_1[0x23] != 2) goto LAB_000ee25a;
    piVar7 = param_1 + 0x51;
    piVar4 = (int *)__rf__7EHANDLE(piVar7);
    iVar6 = *param_2;
    if (iVar6 != *piVar4) {
      iVar6 = __rf__7EHANDLE(piVar7);
      if (*(int *)(iVar6 + 0x120) == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        iVar6 = __rf__7EHANDLE(piVar7);
        pcVar5 = (char *)GetTeamName__Fi(*(undefined4 *)(iVar6 + 0x120));
      }
      piVar4 = (int *)__rf__7EHANDLE(piVar7,pcVar5);
      uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208));
      piVar4 = (int *)__rf__7EHANDLE(piVar7,uVar3);
      uVar3 = (*DAT_0019f864)(*(undefined4 *)(*piVar4 + 0x208));
      piVar7 = (int *)__rf__7EHANDLE(piVar7,uVar3);
      if (param_2[0x48] == 0) {
        pcVar5 = "SPECTATOR";
      }
      else {
        pcVar5 = (char *)GetTeamName__Fi(param_2[0x48],
                                         *(int *)(*piVar7 + 0x1d0) + *(int *)(gpGlobals + 0x98));
      }
      uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar5);
      uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
      iVar6 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
      pcVar5 = 
      "\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_3\" against \"%s<%i><%s><%s>\"\n";
      goto LAB_000ee251;
    }
    if (param_2[0x48] == 0) {
      pcVar5 = "SPECTATOR";
    }
    else {
      pcVar5 = (char *)GetTeamName__Fi(param_2[0x48]);
      iVar6 = *param_2;
    }
    uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(iVar6 + 0x208),pcVar5);
    uVar3 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar3);
    iVar6 = *(int *)(*param_2 + 0x1d0) + *(int *)(gpGlobals + 0x98);
    pcVar5 = "\"%s<%i><%s><%s>\" triggered \"Sentry_Upgrade_Level_3\"\n";
  }
  UTIL_LogPrintf__FPce(pcVar5,iVar6,uVar3);
LAB_000ee25a:
  Upgrade__12CTFSentrygun(param_1);
  return 1;
}


