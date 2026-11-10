// UpdateClientCommandMenu__11CBasePlayer  @ 000de13c
void UpdateClientCommandMenu__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  char *__s1;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1[0x375] == 0) {
    param_1[0x375] = 1;
    (*DAT_001c10d8)(1,gmsgValidClasses,0,*(undefined4 *)(*param_1 + 0x208));
    iVar2 = TeamFortress_TeamIsCivilian__Ff(0);
    uVar5 = illegalclasses;
    if (iVar2 != 0) {
      uVar5 = 0xffffffff;
    }
    (*DAT_001c10e8)(uVar5);
    iVar2 = 1;
    do {
      iVar3 = TeamFortress_TeamIsCivilian__Ff((float)iVar2);
      if (iVar3 == 0) {
        uVar5 = (&illegalclasses)[iVar2];
      }
      else {
        uVar5 = 0xffffffff;
      }
      (*DAT_001c10e8)(uVar5);
      iVar3 = TeamFortress_TeamIsCivilian__Ff((float)(iVar2 + 1));
      if (iVar3 == 0) {
        uVar5 = (&illegalclasses)[iVar2 + 1];
      }
      else {
        uVar5 = 0xffffffff;
      }
      (*DAT_001c10e8)(uVar5);
      iVar3 = TeamFortress_TeamIsCivilian__Ff((float)(iVar2 + 2));
      if (iVar3 == 0) {
        uVar5 = (&illegalclasses)[iVar2 + 2];
      }
      else {
        uVar5 = 0xffffffff;
      }
      (*DAT_001c10e8)(uVar5);
      iVar3 = TeamFortress_TeamIsCivilian__Ff((float)(iVar2 + 3));
      if (iVar3 == 0) {
        uVar5 = (&illegalclasses)[iVar2 + 3];
      }
      else {
        uVar5 = 0xffffffff;
      }
      (*DAT_001c10e8)(uVar5);
      iVar2 = iVar2 + 4;
    } while (iVar2 < 5);
    (*DAT_001c10dc)();
    (*DAT_001c10d8)(1,gmsgTeamNames,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)((int)ROUND(number_of_teams));
    iVar2 = 1;
    do {
      __s1 = (char *)GetTeamName__Fi(iVar2);
      iVar3 = strcasecmp(__s1,"Blue");
      if (iVar3 == 0) {
        __s1 = "#Team_Blue";
      }
      else {
        iVar3 = strcasecmp(__s1,"Red");
        if (iVar3 == 0) {
          __s1 = "#Team_Red";
        }
        else {
          iVar3 = strcasecmp(__s1,"Yellow");
          if (iVar3 == 0) {
            __s1 = "#Team_Yellow";
          }
          else {
            iVar3 = strcasecmp(__s1,"Green");
            if (iVar3 == 0) {
              __s1 = "#Team_Green";
            }
          }
        }
      }
      (*DAT_001c10f8)(__s1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
    (*DAT_001c10dc)();
    g_ClientsAllowSpectator = (int)ROUND((float)allow_spectators._12_4_);
    (*DAT_001c10d8)(1,gmsgAllowSpec,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)(g_ClientsAllowSpectator != 0);
    (*DAT_001c10dc)();
  }
  if (param_1[0x376] != param_1[0x1c]) {
    (*DAT_001c10d8)(1,gmsgFeignState,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)(param_1[0x1c]);
    (*DAT_001c10dc)();
    param_1[0x376] = param_1[0x1c];
  }
  if ((param_1[0x377] != param_1[0x1b]) || (param_1[0x378] != param_1[0x31])) {
    (*DAT_001c10d8)(1,gmsgDetpackState,0,*(undefined4 *)(*param_1 + 0x208));
    if (param_1[0x1b] == 0) {
      if (param_1[0x31] == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 2;
      }
    }
    else {
      uVar5 = 1;
    }
    (*DAT_001c10e0)(uVar5);
    (*DAT_001c10dc)();
    param_1[0x377] = param_1[0x1b];
    param_1[0x378] = param_1[0x31];
  }
  uVar4 = (uint)(param_1[0x1a] != 0);
  fVar1 = (float)param_1[0x54];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (0x81 < param_1[0x37]) {
      uVar4 = uVar4 | 0x10;
    }
  }
  else {
    uVar4 = uVar4 | 4;
  }
  fVar1 = (float)param_1[0x53];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (99 < param_1[0x37]) {
      uVar4 = uVar4 | 8;
    }
  }
  else {
    uVar4 = uVar4 | 2;
  }
  if (param_1[0x379] != uVar4) {
    (*DAT_001c10d8)(1,gmsgBuildState,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)(uVar4);
    (*DAT_001c10dc)();
    param_1[0x379] = uVar4;
  }
  if (param_1[0x37a] != (param_1[0x21] & 8U)) {
    (*DAT_001c10d8)(1,gmsgRandomPC,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)(param_1[0x21] & 8);
    (*DAT_001c10dc)();
    param_1[0x37a] = param_1[0x21] & 8;
  }
  fVar1 = (float)g_ClientsAllowSpectator;
  if ((byte)((float)allow_spectators._12_4_ < fVar1 |
             (byte)((ushort)((ushort)(NAN((float)allow_spectators._12_4_) || NAN(fVar1)) << 10) >> 8
                   ) |
            (byte)((ushort)((ushort)((float)allow_spectators._12_4_ == fVar1) << 0xe) >> 8)) != 0x40
     ) {
    (*DAT_001c10d8)(1,gmsgAllowSpec,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001c10e0)((byte)((byte)((ushort)((ushort)NAN((float)allow_spectators._12_4_) << 10) >> 8)
                          | (byte)((ushort)((ushort)((float)allow_spectators._12_4_ == 0.0) << 0xe)
                                  >> 8)) != 0x40);
    (*DAT_001c10dc)();
    g_ClientsAllowSpectator = (int)ROUND((float)allow_spectators._12_4_);
  }
  return;
}


