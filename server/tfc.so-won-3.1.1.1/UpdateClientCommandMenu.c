// UpdateClientCommandMenu__11CBasePlayer  @ 000dce3c
void UpdateClientCommandMenu__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  char *__s1;
  uint uVar3;
  undefined4 uVar4;
  int local_18;
  
  if (param_1[0x37c] == 0) {
    param_1[0x37c] = 1;
    (*DAT_0019f758)(1,gmsgValidClasses,0,*(undefined4 *)(*param_1 + 0x208));
    local_18 = 0;
    do {
      iVar2 = TeamFortress_TeamIsCivilian__Ff((float)local_18);
      if (iVar2 == 0) {
        (*DAT_0019f768)((&illegalclasses)[local_18]);
      }
      else {
        (*DAT_0019f768)(0xffffffff);
      }
      local_18 = local_18 + 1;
    } while (local_18 < 5);
    (*DAT_0019f75c)();
    (*DAT_0019f758)(1,gmsgTeamNames,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)((int)ROUND(number_of_teams));
    local_18 = 1;
    do {
      __s1 = (char *)GetTeamName__Fi(local_18);
      iVar2 = strcasecmp(__s1,"Blue");
      if (iVar2 == 0) {
        __s1 = "#Team_Blue";
      }
      else {
        iVar2 = strcasecmp(__s1,"Red");
        if (iVar2 == 0) {
          __s1 = "#Team_Red";
        }
        else {
          iVar2 = strcasecmp(__s1,"Yellow");
          if (iVar2 == 0) {
            __s1 = "#Team_Yellow";
          }
          else {
            iVar2 = strcasecmp(__s1,"Green");
            if (iVar2 == 0) {
              __s1 = "#Team_Green";
            }
          }
        }
      }
      (*DAT_0019f778)(__s1);
      local_18 = local_18 + 1;
    } while (local_18 < 5);
    (*DAT_0019f75c)();
    g_ClientsAllowSpectator = (int)ROUND((float)allow_spectators._12_4_);
    (*DAT_0019f758)(1,gmsgAllowSpec,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(g_ClientsAllowSpectator != 0);
    (*DAT_0019f75c)();
  }
  if (param_1[0x37d] != param_1[0x1c]) {
    (*DAT_0019f758)(1,gmsgFeignState,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(param_1[0x1c]);
    (*DAT_0019f75c)();
    param_1[0x37d] = param_1[0x1c];
  }
  if ((param_1[0x37e] != param_1[0x1b]) || (param_1[0x37f] != param_1[0x31])) {
    (*DAT_0019f758)(1,gmsgDetpackState,0,*(undefined4 *)(*param_1 + 0x208));
    if (param_1[0x1b] == 0) {
      if (param_1[0x31] == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = 2;
      }
    }
    else {
      uVar4 = 1;
    }
    (*DAT_0019f760)(uVar4);
    (*DAT_0019f75c)();
    param_1[0x37e] = param_1[0x1b];
    param_1[0x37f] = param_1[0x31];
  }
  uVar3 = (uint)(param_1[0x1a] != 0);
  fVar1 = (float)param_1[0x54];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (0x81 < param_1[0x37]) {
      uVar3 = uVar3 | 0x10;
    }
  }
  else {
    uVar3 = uVar3 | 4;
  }
  fVar1 = (float)param_1[0x53];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (99 < param_1[0x37]) {
      uVar3 = uVar3 | 8;
    }
  }
  else {
    uVar3 = uVar3 | 2;
  }
  if (param_1[0x380] != uVar3) {
    (*DAT_0019f758)(1,gmsgBuildState,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(uVar3);
    (*DAT_0019f75c)();
    param_1[0x380] = uVar3;
  }
  if (param_1[0x381] != (param_1[0x21] & 8U)) {
    (*DAT_0019f758)(1,gmsgRandomPC,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(param_1[0x21] & 8);
    (*DAT_0019f75c)();
    param_1[0x381] = param_1[0x21] & 8;
  }
  fVar1 = (float)g_ClientsAllowSpectator;
  if ((byte)((float)allow_spectators._12_4_ < fVar1 |
             (byte)((ushort)((ushort)(NAN((float)allow_spectators._12_4_) || NAN(fVar1)) << 10) >> 8
                   ) |
            (byte)((ushort)((ushort)((float)allow_spectators._12_4_ == fVar1) << 0xe) >> 8)) != 0x40
     ) {
    (*DAT_0019f758)(1,gmsgAllowSpec,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)((byte)((byte)((ushort)((ushort)NAN((float)allow_spectators._12_4_) << 10) >> 8)
                          | (byte)((ushort)((ushort)((float)allow_spectators._12_4_ == 0.0) << 0xe)
                                  >> 8)) != 0x40);
    (*DAT_0019f75c)();
    g_ClientsAllowSpectator = (int)ROUND((float)allow_spectators._12_4_);
  }
  return;
}


