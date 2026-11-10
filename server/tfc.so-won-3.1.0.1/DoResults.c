// DoResults__FP11CBaseEntityP11CBasePlayeri  @ 000fd0a0
void DoResults__FP11CBaseEntityP11CBasePlayeri(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  int iStack_4;
  
  fVar1 = *gpGlobals;
  if ((((byte)((cb_prematch_time < fVar1 |
                (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8) |
               (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) - 1) < 0x40) ||
      (iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1), iVar2 == 0x81)) && (param_1[0x86] != 1)
     ) {
    if (((float)param_1[0xe1] <= 0.0) || (param_1[0x86] == 4)) {
      param_1[0x86] = 2;
      iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1);
      if ((iVar2 == 0x80) || (iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1), iVar2 == 0x81))
      {
        *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x80;
      }
      iVar2 = *param_1;
      if (*(int *)(iVar2 + 0x1e8) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar2 + 0x208),2,*(int *)(iVar2 + 0x1e8) + (int)gpGlobals[0x26],
                   0x3f800000,0x3f4ccccd,0,100);
      }
      if (param_1[0xba] != 0) {
        TeamFortress_TeamIncreaseScore__Fii(1,param_1[0xba]);
      }
      if (param_1[0xbb] != 0) {
        TeamFortress_TeamIncreaseScore__Fii(2,param_1[0xbb]);
      }
      if (param_1[0xbc] != 0) {
        TeamFortress_TeamIncreaseScore__Fii(3,param_1[0xbc]);
      }
      if (param_1[0xbd] != 0) {
        TeamFortress_TeamIncreaseScore__Fii(4,param_1[0xbd]);
      }
      if (param_1 != (int *)0x0) {
        if (*(char *)(*(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26]) != '\0') {
          if (param_2 == (int *)0x0) {
            UTIL_LogPrintf__FPce
                      ("The goal \"%s\" was activated\n",
                       *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26]);
          }
          else {
            uVar3 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208),
                                    *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26]);
            UTIL_LogPrintf__FPce
                      ("\"%s<%i>\" activated the goal \"%s\"\n",
                       *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
          }
        }
      }
      if (((CTF_Map == 1) && (param_2 != (int *)0x0)) &&
         ((param_1[0x84] == 1 || (param_1[0x84] == 3)))) {
        for (iVar2 = 1; iVar2 <= (int)gpGlobals[0x24]; iVar2 = iVar2 + 1) {
          piVar5 = (int *)UTIL_PlayerByIndex__Fi(iVar2);
          if (piVar5 != (int *)0x0) {
            if (((piVar5[0x48] == 2) && (param_1[0x84] == 1)) ||
               ((piVar5[0x48] == 1 && (param_1[0x84] == 2)))) {
              if (piVar5 != param_2) {
                pcVar4 = "Your team GOT the ENEMY flag!!";
                goto LAB_000fd428;
              }
              pcVar4 = "You got the enemy flag!\n\nReturn to base!";
LAB_000fd3f2:
              iVar6 = *param_2;
            }
            else {
              if (param_1[0x84] - 1U < 2) {
                pcVar4 = "Your flag has been TAKEN!!";
              }
              else if (((piVar5[0x48] == 2) && (param_1[0x84] == 3)) ||
                      ((piVar5[0x48] == 1 && (param_1[0x84] == 4)))) {
                if (piVar5 == param_2) {
                  pcVar4 = "You CAPTURED the FLAG!!";
                  goto LAB_000fd3f2;
                }
                pcVar4 = "Your flag was CAPTURED!!";
              }
              else {
                if (1 < param_1[0x84] - 3U) goto LAB_000fd436;
                pcVar4 = "Your team CAPTURED the flag!!";
              }
LAB_000fd428:
              iVar6 = *piVar5;
            }
            ClientPrint__FP9entvars_siPCcN42(iVar6,4,pcVar4,0,0,0,0);
          }
LAB_000fd436:
        }
        switch(param_1[0x84]) {
        case 1:
          uVar3 = UTIL_VarArgs__FPce("%s GOT the BLUE flag!",
                                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar3);
          UTIL_LogPrintf__FPce
                    ("%s GOT the \"BLUE\" flag!",*(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26]);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 2;
          break;
        case 2:
          uVar3 = UTIL_VarArgs__FPce("%s GOT the RED flag!",
                                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar3);
          UTIL_LogPrintf__FPce
                    ("%s GOT the \"RED\" flag!",*(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26]);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) | 4;
          break;
        case 3:
          uVar3 = UTIL_VarArgs__FPce("%s CAPTURED the RED flag!",
                                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar3);
          UTIL_LogPrintf__FPce
                    ("%s CAPTURED the \"RED\" flag!",
                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26]);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfb;
          break;
        case 4:
          uVar3 = UTIL_VarArgs__FPce("%s CAPTURED the BLUE flag!",
                                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar3);
          UTIL_LogPrintf__FPce
                    ("%s CAPTURED the \"BLUE\" flag!",
                     *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26]);
          *(byte *)((int)param_2 + 0x8a) = *(byte *)((int)param_2 + 0x8a) & 0xfd;
        }
      }
      if (param_1[0xac] != 0) {
        iVar2 = 0;
        while (iVar2 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                 (iVar2,"netname","info_player_teamspawn"), iVar2 != 0) {
          if (*(int *)(iVar2 + 0x214) == param_1[0xac]) {
            InactivateSpawn__FP11CBaseEntity(iVar2);
          }
        }
      }
      if (param_1[0xad] != 0) {
        iVar2 = 0;
        while (iVar2 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                 (iVar2,"netname","info_player_teamspawn"), iVar2 != 0) {
          if (*(int *)(iVar2 + 0x214) == param_1[0xad]) {
            ActivateSpawn__FP11CBaseEntity(iVar2);
          }
        }
      }
      if ((param_1[0xcb] != 0) && (CTF_Map == 0)) {
        UTIL_LogPrintf__FPce("Broadcast: \"%s\"\n",param_1[0xcb] + (int)gpGlobals[0x26]);
      }
      if (((param_1[0xd0] != 0) && (CTF_Map == 0)) && (param_2 != (int *)0x0)) {
        uVar3 = (*DAT_001a8004)(*(undefined4 *)(*param_2 + 0x208));
        UTIL_LogPrintf__FPce
                  (FUN_001414e0,param_1[0xd0] + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
      }
      iStack_4 = 1;
      if (0 < (int)gpGlobals[0x24]) {
        do {
          piVar5 = (int *)UTIL_PlayerByIndex__Fi(iStack_4);
          if (piVar5 != (int *)0x0) {
            if ((param_1[0xcb] != 0) && (CTF_Map == 0)) {
              ClientPrint__FP9entvars_siPCcN42
                        (*piVar5,4,param_1[0xcb] + (int)gpGlobals[0x26],0,0,0,0);
            }
            if (((param_1[0xd0] != 0) && (CTF_Map == 0)) && (param_2 != (int *)0x0)) {
              ClientPrint__FP9entvars_siPCcN42
                        (*piVar5,1,param_1[0xd0] + (int)gpGlobals[0x26],
                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0,0);
            }
            if (param_1[0xd4] != 0) {
              ClientHearVox__11CBasePlayerPCc(piVar5,param_1[0xd4] + (int)gpGlobals[0x26]);
            }
            if (param_2 == piVar5) {
              if ((*(int *)(*param_1 + 0x1d4) != 0) &&
                 (iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1), iVar2 != 0x83)) {
                ClientPrint__FP9entvars_siPCcN42
                          (*param_2,4,*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26],0,0,0,0);
              }
              if (param_1[0xd5] != 0) {
                ClientHearVox__11CBasePlayerPCc(piVar5,param_1[0xd5] + (int)gpGlobals[0x26]);
              }
            }
            else {
              if ((param_2 == (int *)0x0) || (param_2[0x48] != piVar5[0x48])) {
                if ((param_1[0xce] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if ((param_1[0xcf] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    iVar2 = param_1[0xcf];
                    goto LAB_000fdab3;
                  }
                  if (param_1[0xcd] != 0) {
                    iVar2 = param_1[0xcd];
                    goto LAB_000fdab3;
                  }
                }
                else {
                  iVar2 = param_1[0xce];
LAB_000fdab3:
                  ClientPrint__FP9entvars_siPCcN42(*piVar5,4,iVar2 + (int)gpGlobals[0x26],0,0,0,0);
                }
                if ((param_1[0xd8] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if ((param_1[0xd9] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    iVar2 = param_1[0xd9];
                    goto LAB_000fdb2f;
                  }
                  if (param_1[0xd7] != 0) {
                    iVar2 = param_1[0xd7];
                    goto LAB_000fdb2f;
                  }
                }
                else {
                  iVar2 = param_1[0xd8];
LAB_000fdb2f:
                  ClientHearVox__11CBasePlayerPCc(piVar5,iVar2 + (int)gpGlobals[0x26]);
                }
                if (((param_1[0xd3] != 0) && (piVar5[0x48] == param_1[0x87])) &&
                   (param_2 != (int *)0x0)) goto LAB_000fdb5a;
                if ((param_1[0xd2] == 0) || (param_2 == (int *)0x0)) goto LAB_000fdbcb;
                iVar6 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
                iVar2 = param_1[0xd2];
              }
              else {
                if ((param_1[0xce] == 0) || (param_2[0x48] != param_1[0x87])) {
                  if ((param_1[0xcf] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    iVar2 = param_1[0xcf];
                    goto LAB_000fd953;
                  }
                  if (param_1[0xcc] != 0) {
                    iVar2 = param_1[0xcc];
                    goto LAB_000fd953;
                  }
                }
                else {
                  iVar2 = param_1[0xce];
LAB_000fd953:
                  ClientPrint__FP9entvars_siPCcN42(*piVar5,4,iVar2 + (int)gpGlobals[0x26],0,0,0,0);
                }
                if ((param_1[0xd8] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if ((param_1[0xd9] != 0) && (piVar5[0x48] != param_1[0x87])) {
                    iVar2 = param_1[0xd9];
                    goto LAB_000fd9cf;
                  }
                  if (param_1[0xd6] != 0) {
                    iVar2 = param_1[0xd6];
                    goto LAB_000fd9cf;
                  }
                }
                else {
                  iVar2 = param_1[0xd8];
LAB_000fd9cf:
                  ClientHearVox__11CBasePlayerPCc(piVar5,iVar2 + (int)gpGlobals[0x26]);
                }
                if ((param_1[0xd3] == 0) || (piVar5[0x48] != param_1[0x87])) {
                  if (param_1[0xd1] != 0) {
                    iVar6 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
                    iVar2 = param_1[0xd1];
                    goto LAB_000fdbb7;
                  }
                  goto LAB_000fdbcb;
                }
LAB_000fdb5a:
                iVar6 = *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26];
                iVar2 = param_1[0xd3];
              }
LAB_000fdbb7:
              ClientPrint__FP9entvars_siPCcN42(*piVar5,1,iVar2 + (int)gpGlobals[0x26],iVar6,0,0,0);
            }
LAB_000fdbcb:
            iVar2 = IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1(param_1,piVar5,param_2);
            if ((iVar2 != 0) &&
               (((fVar1 = (float)param_1[0x93],
                 (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 ||
                 ((*(byte *)(param_1 + 0x89) & 0x40) == 0)) ||
                (iVar2 = APMeetsCriteria__FP11CBaseEntityT0(param_1,piVar5), iVar2 != 0)))) {
              Apply_Results__FP11CBaseEntityP11CBasePlayerT1i(param_1,piVar5,param_2,param_3);
            }
          }
          iStack_4 = iStack_4 + 1;
        } while (iStack_4 <= (int)gpGlobals[0x24]);
      }
      iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1);
      if ((iVar2 == 0x81) || (iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1), iVar2 == 0x80))
      {
        param_1[0x86] = 1;
      }
      if ((*(byte *)(param_1 + 0x8a) & 4) == 0) {
        DoGroupWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        DoGoalWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1);
        if (((iVar2 == 0x81) ||
            (iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1), iVar2 == 0x82)) ||
           ((iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1), iVar2 == 0x80 ||
            ((iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1), iVar2 == 0x83 ||
             (param_1[0xe2] == 1)))))) {
          DoTriggerWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        }
        iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1);
        if ((iVar2 == 0x80) || (iVar2 = (**(code **)(param_1[0xf5] + 0x28))(param_1), iVar2 == 0x81)
           ) {
          SetupRespawn__FP11CBaseEntity(param_1);
        }
      }
      else {
        TeamFortress_TeamShowScores__FiP11CBasePlayer(1,0);
        iVar2 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
        if (iVar2 != 0) {
          (**(code **)(*g_pGameRules + 0xe0))(g_pGameRules);
        }
      }
    }
    else {
      param_1[0x86] = 4;
      CreateTimer__11CBaseEntityi(param_1,0x65);
      *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_2 + 0x208);
      param_1[3] = -0x10000;
      param_1[4] = (int)DelayedResult__11CBaseEntity;
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0xe1];
      param_1[0x23] = param_3;
    }
  }
  return;
}


