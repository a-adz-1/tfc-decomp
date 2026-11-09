// DoResults__FP11CBaseEntityP11CBasePlayeri  @ 0010b750
void DoResults__FP11CBaseEntityP11CBasePlayeri(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  
  if ((cb_prematch_time <= *gpGlobals) && (param_1[0x86] != 1)) {
    fVar1 = (float)param_1[0xde];
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) && (param_1[0x86] != 4))
    {
      param_1[0x86] = 4;
      CreateTimer__11CBaseEntityi(param_1,0x65);
      *(undefined4 *)(*param_1 + 0x170) = *(undefined4 *)(*param_2 + 0x1e8);
      param_1[3] = -0x10000;
      param_1[4] = (int)DelayedResult__11CBaseEntity;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0xde];
      param_1[0x24] = param_3;
    }
    else {
      param_1[0x86] = 2;
      iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1);
      if ((iVar3 == 0x80) || (iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1), iVar3 == 0x81))
      {
        *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x80;
      }
      iVar3 = *param_1;
      if (*(int *)(iVar3 + 0x1c8) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar3 + 0x1e8),2,*(int *)(iVar3 + 0x1c8) + (int)gpGlobals[0x26],
                   0x3f800000,0x3f4ccccd,0,100);
      }
      bVar2 = false;
      iVar3 = 0;
      do {
        if (param_1[iVar3 + 0xba] != 0) {
          TeamFortress_TeamIncreaseScore__Fii(iVar3 + 1,param_1[iVar3 + 0xba]);
          bVar2 = true;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
      if (bVar2) {
        TeamFortress_TeamShowScores__FiP11CBasePlayer(0,0);
      }
      if (((CTF_Map == 1) && (param_2 != (int *)0x0)) &&
         ((param_1[0x84] == 1 || (param_1[0x84] == 3)))) {
        for (iVar3 = 1; iVar3 <= (int)gpGlobals[0x24]; iVar3 = iVar3 + 1) {
          piVar5 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
          if (piVar5 != (int *)0x0) {
            if (((piVar5[0x48] == 2) && (param_1[0x84] == 1)) ||
               ((piVar5[0x48] == 1 && (param_1[0x84] == 2)))) {
              if (piVar5 != param_2) {
                pcVar9 = "Your team GOT the ENEMY flag!!";
                goto LAB_0010ba2b;
              }
              pcVar9 = "You got the enemy flag!\n\nReturn to base!";
              iVar6 = *param_2;
            }
            else {
              if (param_1[0x84] - 1U < 2) {
                pcVar9 = "Your flag has been TAKEN!!";
              }
              else if (((piVar5[0x48] == 2) && (param_1[0x84] == 3)) ||
                      ((piVar5[0x48] == 1 && (param_1[0x84] == 4)))) {
                if (piVar5 == param_2) {
                  pcVar9 = "You CAPTURED the FLAG!!";
                  iVar6 = *param_2;
                  goto LAB_0010ba30;
                }
                pcVar9 = "Your flag was CAPTURED!!";
              }
              else {
                if (1 < param_1[0x84] - 3U) goto LAB_0010ba38;
                pcVar9 = "Your team CAPTURED the flag!!";
              }
LAB_0010ba2b:
              iVar6 = *piVar5;
            }
LAB_0010ba30:
            ClientPrint__FP9entvars_tiPCcN42(iVar6,4,pcVar9,0,0,0,0);
          }
LAB_0010ba38:
        }
        iVar3 = param_1[0x84];
        if (iVar3 == 2) {
          uVar4 = UTIL_VarArgs__FPce("%s GOT the RED flag!",
                                     *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
          *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 4;
        }
        else if (iVar3 < 3) {
          if (iVar3 == 1) {
            uVar4 = UTIL_VarArgs__FPce("%s GOT the BLUE flag!",
                                       *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0,0,0);
            UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
            *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) | 2;
          }
        }
        else if (iVar3 == 3) {
          uVar4 = UTIL_VarArgs__FPce("%s CAPTURED the RED flag!",
                                     *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
          *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) & 0xfb;
        }
        else if (iVar3 == 4) {
          uVar4 = UTIL_VarArgs__FPce("%s CAPTURED the BLUE flag!",
                                     *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0,0,0);
          UTIL_ClientPrintAll__FiPCcN41(1,uVar4);
          *(byte *)((int)param_2 + 0x8e) = *(byte *)((int)param_2 + 0x8e) & 0xfd;
        }
      }
      if (param_1[0xac] != 0) {
        iVar3 = 0;
        while (iVar3 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                 (iVar3,"netname","info_player_teamspawn"), iVar3 != 0) {
          if (*(int *)(iVar3 + 0x214) == param_1[0xac]) {
            InactivateSpawn__FP11CBaseEntity(iVar3);
          }
        }
      }
      if (param_1[0xad] != 0) {
        iVar3 = 0;
        while (iVar3 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                                 (iVar3,"netname","info_player_teamspawn"), iVar3 != 0) {
          if (*(int *)(iVar3 + 0x214) == param_1[0xad]) {
            ActivateSpawn__FP11CBaseEntity(iVar3);
          }
        }
      }
      for (iVar3 = 1; iVar3 <= (int)gpGlobals[0x24]; iVar3 = iVar3 + 1) {
        piVar5 = (int *)UTIL_PlayerByIndex__Fi(iVar3);
        if (piVar5 != (int *)0x0) {
          if ((param_1[0xca] != 0) && (CTF_Map == 0)) {
            ClientPrint__FP9entvars_tiPCcN42(*piVar5,4,param_1[0xca] + (int)gpGlobals[0x26],0,0,0,0)
            ;
          }
          if (((param_1[0xce] != 0) && (CTF_Map == 0)) && (param_2 != (int *)0x0)) {
            ClientPrint__FP9entvars_tiPCcN42
                      (*piVar5,1,param_1[0xce] + (int)gpGlobals[0x26],
                       *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0,0);
          }
          if (param_1[0xd2] != 0) {
            ClientHearVox__11CBasePlayerPCc(piVar5,param_1[0xd2] + (int)gpGlobals[0x26]);
          }
          if (param_2 == piVar5) {
            if ((*(int *)(*param_1 + 0x1b4) != 0) &&
               (iVar6 = (**(code **)(param_1[0xf2] + 0x28))(param_1), iVar6 != 0x83)) {
              ClientPrint__FP9entvars_tiPCcN42
                        (*param_2,4,*(int *)(*param_1 + 0x1b4) + (int)gpGlobals[0x26],0,0,0,0);
            }
            if (param_1[0xd3] != 0) {
              ClientHearVox__11CBasePlayerPCc(piVar5,param_1[0xd3] + (int)gpGlobals[0x26]);
            }
          }
          else {
            if ((param_2 == (int *)0x0) || (param_2[0x48] != piVar5[0x48])) {
              if ((param_1[0xcd] == 0) || (piVar5[0x48] != param_1[0x87])) {
                if (param_1[0xcc] != 0) {
                  iVar6 = param_1[0xcc];
                  goto LAB_0010bf2c;
                }
              }
              else {
                iVar6 = param_1[0xcd];
LAB_0010bf2c:
                ClientPrint__FP9entvars_tiPCcN42(*piVar5,4,iVar6 + (int)gpGlobals[0x26],0,0,0,0);
              }
              if ((param_1[0xd6] == 0) || (piVar5[0x48] != param_1[0x87])) {
                if (param_1[0xd5] != 0) {
                  iVar6 = param_1[0xd5];
                  goto LAB_0010bf85;
                }
              }
              else {
                iVar6 = param_1[0xd6];
LAB_0010bf85:
                ClientHearVox__11CBasePlayerPCc(piVar5,iVar6 + (int)gpGlobals[0x26]);
              }
              if (((param_1[0xd1] != 0) && (piVar5[0x48] == param_1[0x87])) &&
                 (param_2 != (int *)0x0)) goto LAB_0010bfb2;
              if ((param_1[0xd0] == 0) || (param_2 == (int *)0x0)) goto LAB_0010c036;
              iVar7 = *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26];
              iVar6 = param_1[0xd0];
LAB_0010c022:
              iVar6 = iVar6 + (int)gpGlobals[0x26];
              iVar8 = *piVar5;
            }
            else {
              if ((param_1[0xcd] == 0) || (param_2[0x48] != param_1[0x87])) {
                if (param_1[0xcb] != 0) {
                  iVar6 = param_1[0xcb];
                  goto LAB_0010be1c;
                }
              }
              else {
                iVar6 = param_1[0xcd];
LAB_0010be1c:
                ClientPrint__FP9entvars_tiPCcN42(*piVar5,4,iVar6 + (int)gpGlobals[0x26],0,0,0,0);
              }
              if ((param_1[0xd6] == 0) || (piVar5[0x48] != param_1[0x87])) {
                if (param_1[0xd4] != 0) {
                  iVar6 = param_1[0xd4];
                  goto LAB_0010be75;
                }
              }
              else {
                iVar6 = param_1[0xd6];
LAB_0010be75:
                ClientHearVox__11CBasePlayerPCc(piVar5,iVar6 + (int)gpGlobals[0x26]);
              }
              if ((param_1[0xd1] == 0) || (piVar5[0x48] != param_1[0x87])) {
                if (param_1[0xcf] != 0) {
                  iVar7 = *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26];
                  iVar6 = param_1[0xcf];
                  goto LAB_0010c022;
                }
                goto LAB_0010c036;
              }
LAB_0010bfb2:
              iVar7 = *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26];
              iVar6 = param_1[0xd1] + (int)gpGlobals[0x26];
              iVar8 = *piVar5;
            }
            ClientPrint__FP9entvars_tiPCcN42(iVar8,1,iVar6,iVar7,0,0,0);
          }
LAB_0010c036:
          iVar6 = IsAffectedBy__FP11CBaseEntityP11CBasePlayerT1(param_1,piVar5,param_2);
          if ((iVar6 != 0) &&
             (((fVar1 = (float)param_1[0x93],
               (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40 ||
               ((*(byte *)(param_1 + 0x89) & 0x40) == 0)) ||
              (iVar6 = APMeetsCriteria__FP11CBaseEntityT0(param_1,piVar5), iVar6 != 0)))) {
            Apply_Results__FP11CBaseEntityP11CBasePlayerT1i(param_1,piVar5,param_2,param_3);
          }
        }
      }
      iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1);
      if ((iVar3 == 0x81) || (iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1), iVar3 == 0x80))
      {
        param_1[0x86] = 1;
      }
      if ((*(byte *)(param_1 + 0x8a) & 4) == 0) {
        DoGroupWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        DoGoalWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1);
        if (((iVar3 == 0x81) ||
            (iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1), iVar3 == 0x82)) ||
           ((iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1), iVar3 == 0x80 ||
            ((iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1), iVar3 == 0x83 ||
             (param_1[0xdf] == 1)))))) {
          DoTriggerWork__FP11CBaseEntityP11CBasePlayer(param_1,param_2);
        }
        iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1);
        if ((iVar3 == 0x80) || (iVar3 = (**(code **)(param_1[0xf2] + 0x28))(param_1), iVar3 == 0x81)
           ) {
          SetupRespawn__FP11CBaseEntity(param_1);
        }
      }
      else {
        TeamFortress_TeamShowScores__FiP11CBasePlayer(1,0);
        iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
        if (iVar3 != 0) {
          (**(code **)(*g_pGameRules + 0xe0))(g_pGameRules);
          FUN_0010c1c7();
          return;
        }
      }
    }
  }
  return;
}


