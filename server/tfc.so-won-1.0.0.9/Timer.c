// Timer_AutokickThink__11CBaseEntity  @ 00106870
void Timer_AutokickThink__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x178);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_001068a2;
    }
  }
  iVar1 = *(int *)(iVar1 + 0xd8);
LAB_001068a2:
  *(undefined4 *)(iVar1 + 0x1f8) = 0;
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_Birthday__11CBaseEntity  @ 001055f0
void Timer_Birthday__11CBaseEntity(int *param_1)

{
  bool bVar1;
  float *pfVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  longdouble lVar7;
  undefined4 uVar8;
  
  pfVar2 = gpGlobals;
  if (5 < param_1[0x24]) {
    param_1[0x24] = 0;
    lVar7 = (longdouble)(*DAT_0017562c)(0x43340000,0x43700000);
    *(float *)(*param_1 + 0xe4) = (float)(lVar7 + (longdouble)*gpGlobals);
    lVar7 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
    if ((longdouble)0.02 <= lVar7) {
      if (lVar7 < (longdouble)0.04) {
        lVar7 = (longdouble)(*DAT_0017562c)(0x447a0000,0x459c4000);
        iVar4 = UTIL_VarArgs__FPce("\n\n\n\nCurrent number of Snipers on\nthe Battlements Worldwide: %d\n"
                                   ,(double)lVar7);
        param_1[0xb3] = iVar4 - (int)gpGlobals[0x26];
        FUN_00106110();
        return;
      }
      if ((longdouble)0.06 <= lVar7) {
        if ((longdouble)0.08 <= lVar7) {
          if ((longdouble)0.1 <= lVar7) {
            if ((longdouble)0.12 <= lVar7) {
              if ((longdouble)0.14 <= lVar7) {
                if ((longdouble)0.16 <= lVar7) {
                  if ((longdouble)0.18 <= lVar7) {
                    if ((longdouble)0.2 <= lVar7) {
                      if ((longdouble)0.22 <= lVar7) {
                        if ((longdouble)0.24 <= lVar7) {
                          if ((longdouble)0.25 <= lVar7) {
                            if ((longdouble)0.26 <= lVar7) {
                              if ((longdouble)0.28 <= lVar7) {
                                if ((longdouble)0.3 <= lVar7) {
                                  if ((longdouble)0.32 <= lVar7) {
                                    if ((longdouble)0.34 <= lVar7) {
                                      if ((longdouble)0.36 <= lVar7) {
                                        if ((longdouble)0.38 <= lVar7) {
                                          if ((longdouble)0.4 <= lVar7) {
                                            if ((longdouble)0.42 <= lVar7) {
                                              if ((longdouble)0.44 <= lVar7) {
                                                if ((longdouble)0.46 <= lVar7) {
                                                  if ((longdouble)0.48 <= lVar7) {
                                                    if ((longdouble)0.5 <= lVar7) {
                                                      if ((longdouble)0.52 <= lVar7) {
                                                        if ((longdouble)0.54 <= lVar7) {
                                                          if ((longdouble)0.56 <= lVar7) {
                                                            if ((longdouble)0.58 <= lVar7) {
                                                              if ((longdouble)0.6 <= lVar7) {
                                                                if ((longdouble)0.62 <= lVar7) {
                                                                  if ((longdouble)0.64 <= lVar7) {
                                                                    if ((longdouble)0.66 <= lVar7) {
                                                                      if ((longdouble)0.68 <= lVar7)
                                                                      {
                                                                        if ((longdouble)0.7 <= lVar7
                                                                           ) {
                                                                          if ((longdouble)0.72 <=
                                                                              lVar7) {
                                                                            if ((longdouble)0.74 <=
                                                                                lVar7) {
                                                                              if ((longdouble)0.76
                                                                                  <= lVar7) {
                                                                                if ((longdouble)0.78
                                                                                    <= lVar7) {
                                                                                  if ((longdouble)
                                                                                      0.8 <= lVar7)
                                                                                  {
                                                                                    if ((longdouble)
                                                                                        0.82 <= 
                                                  lVar7) {
                                                    if ((longdouble)0.84 <= lVar7) {
                                                      if ((longdouble)0.86 <= lVar7) {
                                                        if ((longdouble)0.88 <= lVar7) {
                                                          if ((longdouble)0.9 <= lVar7) {
                                                            if ((longdouble)0.92 <= lVar7) {
                                                              if ((longdouble)0.94 <= lVar7) {
                                                                if ((longdouble)0.96 <= lVar7) {
                                                                  if ((longdouble)0.98 <= lVar7) {
                                                                    pcVar3 = 
                                                  "\n\n\n\n\"MJ: Did you hear John Cash wrote TF?\"\n   - VomitGod"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_2.gif"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_1.gif"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #10:\nWhy is that guy running\nout of our yard with\nthe flag???\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #9:\nI was typing!!\n";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #8:\nSpy\'s, please change colors\noutside our base.\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #7:\nGet a mask or\nget in the WATER!!\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #6:\nDamn Snipers!\n";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #5:\nDamn Snipers!\n";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #4:\nDISCARD!!\n";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #3:\nWho the hell is on\nthe lift?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #2:\nGuys could you NOT set up\nsentries in Hunted?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #1:\nUm, Red Medics, please don\'t\nheal the Hunted.\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #10:\nWhat\'s this key? I thought this\nwas a CTF style map, guys?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #9:\nStop shooting me!\nI\'m on your team!\nYou tried to attack my with the axe!\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #8:\nWho\'s the maniac with the axe?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #7:\nWhy the hell are these backpacks\nexploding?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #6:\nWhere\'s the control room?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #5:\nWhere do I take the flag!?!?!\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #4:\nHow do I throw the pins?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #3:\nHey, he is cheating, that soldier just jumped up to the roof!!\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #2:\nUmm... How do I throw a grenade?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #1:\nUmm... How do I set a detpack?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen  Ian went to jail for punching\nRobin out\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen the motion detector was officially\nthe Scout\'s best friend, at least\naccording to the readme.txt\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen The Well actually had a well...\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen players used to say\n\"What\'s that bubble?\"\n"
                                                  ;
                                                  }
                                                }
                                                else {
                                                  pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen I didn\'t have to download\nANYTHING to play TF\n"
                                                  ;
                                                }
                                              }
                                              else {
                                                pcVar3 = 
                                                "\n\n\n\nI remember the good ol\' days...\nwhen I could download TF in\n1 minute 20 seconds\n"
                                                ;
                                              }
                                            }
                                            else {
                                              pcVar3 = 
                                              "\n\n\n\nI remember the good ol\' days...\nwhen the sniper rifle just\nkilled in one hit... everytime\n"
                                              ;
                                            }
                                          }
                                          else {
                                            pcVar3 = 
                                            "\n\n\n\nI remember the good ol\' days...\nwhen 2fort was the only TF map.\nWe sure have come a long\nway since then... sigh"
                                            ;
                                          }
                                        }
                                        else {
                                          pcVar3 = 
                                          "\n\n\n\nI remember the good ol\' days...\nwhen no-one knew how to use\nhand grenades...\n"
                                          ;
                                        }
                                      }
                                      else {
                                        pcVar3 = 
                                        "\n\n\n\nI remember the good ol\' days...\nwhen there were 2 TF servers...\nand they were always down."
                                        ;
                                      }
                                    }
                                    else {
                                      pcVar3 = 
                                      "\n\n\n\nI remember the good ol\' days...\nwhen you had to use imin1 & imin2\nto join a team.\n"
                                      ;
                                    }
                                  }
                                  else {
                                    pcVar3 = 
                                    "\n\n\n\n\"I force them to work.\nElse I cut back their supplies\"\n   - Vomitgod, on TFS\n"
                                    ;
                                  }
                                }
                                else {
                                  pcVar3 = 
                                  "\n\n\n\n\"After all, TF is an INSULT to the\npurity of CTF!\"\n   - Mjollnir, who was joking... really!"
                                  ;
                                }
                              }
                              else {
                                pcVar3 = 
                                "\n\n\n\n\"Twin Peaks will be finished tomorrow.\"\n   - TyR, 16th July, 25th July, 2nd August..."
                                ;
                              }
                            }
                            else {
                              pcVar3 = "\n\n\n\nTwin Peaks will be out... uhh...\nerr... soon.\n";
                            }
                          }
                          else {
                            pcVar3 = 
                            "\n\n\n\nBAH! I shoulda put the Demoman\nblast armor back while I was at it!\n   - Gudlyf\n"
                            ;
                          }
                        }
                        else {
                          pcVar3 = 
                          "\n\n\n\nMany potatoes were harmed in the\nmaking of this product.\n";
                        }
                      }
                      else {
                        pcVar3 = 
                        "\n\n\n\n\"You guys have really screwed up\n urinals, you know that?\"\n   - TyR in Australia\n"
                        ;
                      }
                    }
                    else {
                      pcVar3 = "\n\n\n\nDeath to Potatoes!\n";
                    }
                  }
                  else {
                    pcVar3 = 
                    "\n\n\n\nKill your friends! Kill your family!\nSnipe your pets! Detpack your house!\nGet TF Now!\n"
                    ;
                  }
                }
                else {
                  pcVar3 = "\n\n\n\nhmm.... I wonder what the next\nmessage will be...\n";
                }
              }
              else {
                pcVar3 = "\n\n\n\nTF II available soon!\n";
              }
            }
            else {
              pcVar3 = "\n\n\n\nTeamFortress is one year old today!\n";
            }
          }
          else {
            pcVar3 = "\n\n\n\n25,000 downloads\n50 donations\nDamn, but we rock!\n";
          }
        }
        else {
          pcVar3 = 
          "\n\n\n\nIs that an assault cannon in your\n pocket, or are you just playing TF?\n(Blame Ian)\n"
          ;
        }
      }
      else {
        pcVar3 = "\n\n\n\nYeeha!\nThe 505,672nd detpack was\njust laid on the bridge!\n";
      }
    }
    else if (christmas == 0) {
      pcVar3 = "\n\n\n\nHAPPY BIRTHDAY TEAMFORTRESS!\n";
    }
    else {
      pcVar3 = "\n\n\n\nMERRY CHRISTMAS!!\n";
    }
    param_1[0xb3] = (int)pcVar3 - (int)gpGlobals[0x26];
    FUN_00106110();
    return;
  }
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.5;
  param_1[0x24] = param_1[0x24] + 1;
  UTIL_ClientPrintAll__FiPCcN41(4,param_1[0xb3] + (int)pfVar2[0x26],0,0,0,0);
  piVar6 = (int *)0x0;
LAB_00105ff4:
  do {
    piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"player");
    if (piVar6 == (int *)0x0) {
      return;
    }
    bVar1 = false;
    if ((*(int *)(*piVar6 + 0x1e8) == 0) ||
       (iVar4 = (*DAT_001755d8)(*(int *)(*piVar6 + 0x1e8)), iVar4 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      return;
    }
  } while ((*piVar6 == 0) || (piVar6[0x1f] != 0));
  if (param_1[0x24] != 1) goto LAB_001060a0;
  if (christmas == 0) {
    uVar5 = *(undefined4 *)(*piVar6 + 0x1e8);
    pcVar3 = "misc/b1.wav";
    uVar8 = 2;
  }
  else {
    uVar5 = *(undefined4 *)(*piVar6 + 0x1e8);
    pcVar3 = "misc/b2.wav";
    uVar8 = 2;
  }
  goto LAB_001060fd;
LAB_001060a0:
  if (param_1[0x24] < 5) {
    iVar4 = (*DAT_00175628)(0,1);
    if (iVar4 == 0) {
      uVar5 = *(undefined4 *)(*piVar6 + 0x1e8);
      pcVar3 = "misc/party1.wav";
    }
    else {
      uVar5 = *(undefined4 *)(*piVar6 + 0x1e8);
      pcVar3 = "misc/party2.wav";
    }
    uVar8 = 3;
LAB_001060fd:
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,uVar8,pcVar3,0x3f4ccccd3f800000,0,100);
  }
  goto LAB_00105ff4;
}


// Timer_CeaseFireThink__11CBaseEntity  @ 00106740
void Timer_CeaseFireThink__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  if (((cb_ceasefire_time < *gpGlobals) && (param_1[0x24] == 1)) && (cease_fire == 1)) {
    cease_fire = 0;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
    UTIL_LogPrintf__FPce("RESUME FIRE\n");
    piVar3 = (int *)0x0;
    while( true ) {
      piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"player");
      if (piVar3 == (int *)0x0) break;
      bVar1 = false;
      if (*(int *)(*piVar3 + 0x1e8) == 0) {
LAB_001067d9:
        bVar1 = true;
      }
      else {
        iVar2 = (*DAT_001755d8)(*(int *)(*piVar3 + 0x1e8));
        if (iVar2 == 0) goto LAB_001067d9;
      }
      if (bVar1) break;
      if (*piVar3 != 0) {
        piVar3[99] = (int)(*gpGlobals + 10.0);
        *(byte *)((int)piVar3 + 0x8a) = *(byte *)((int)piVar3 + 0x8a) & 0xfe;
        TeamFortress_SetSpeed__11CBasePlayer(piVar3);
      }
    }
  }
  if (cease_fire == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_ceasefire",0,0,0,0);
    UTIL_LogPrintf__FPce("CEASE FIRE\n");
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 5.0;
  }
  return;
}


// Timer_CheckBuildDistance__11CBaseEntity  @ 00106380
void Timer_CheckBuildDistance__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int **ppiVar9;
  int *piStack_44;
  code *pcStack_40;
  int *piStack_3c;
  
  bVar4 = false;
  if (*(int **)(*param_1 + 0x178) == (int *)0x0) {
LAB_001063a9:
    bVar4 = true;
  }
  else {
    pcStack_40 = (code *)0x1063a2;
    piStack_3c = *(int **)(*param_1 + 0x178);
    iVar5 = (*DAT_001755d8)();
    if (iVar5 == 0) goto LAB_001063a9;
  }
  ppiVar9 = (int **)&stack0xffffffc8;
  if (bVar4) goto LAB_001064cd;
  bVar4 = false;
  if (*(int **)(*param_1 + 0x170) == (int *)0x0) {
LAB_001063d6:
    bVar4 = true;
  }
  else {
    pcStack_40 = (code *)0x1063cf;
    piStack_3c = *(int **)(*param_1 + 0x170);
    iVar5 = (*DAT_001755d8)();
    if (iVar5 == 0) goto LAB_001063d6;
  }
  ppiVar9 = (int **)&stack0xffffffc8;
  if (bVar4) goto LAB_001064cd;
  iVar5 = *(int *)(*param_1 + 0x178);
  if (iVar5 == 0) {
    piStack_3c = (int *)0x0;
    pcStack_40 = (code *)0x1063fb;
    iVar5 = (*DAT_001755d4)();
    if (iVar5 != 0) goto LAB_00106404;
    piVar7 = (int *)0x0;
  }
  else {
LAB_00106404:
    piVar7 = *(int **)(iVar5 + 0xd8);
  }
  iVar5 = *(int *)(*param_1 + 0x170);
  if (iVar5 == 0) {
    piStack_3c = (int *)0x0;
    pcStack_40 = (code *)0x10642c;
    iVar5 = (*DAT_001755d4)();
    if (iVar5 != 0) goto LAB_00106435;
    piVar8 = (int *)0x0;
  }
  else {
LAB_00106435:
    piVar8 = *(int **)(iVar5 + 0xd8);
  }
  pcStack_40 = FUN_00106450;
  piStack_3c = piVar7 + 0x4e;
  iVar5 = __opP11CBaseEntity__7EHANDLE();
  ppiVar9 = (int **)&stack0xffffffc8;
  if (iVar5 != 0) {
    pcStack_40 = (code *)0x10645d;
    piStack_3c = piVar7 + 0x4e;
    piVar6 = (int *)__opP11CBaseEntity__7EHANDLE();
    ppiVar9 = (int **)&stack0xffffffc8;
    if (piVar6 == piVar8) {
      iVar5 = *piVar8;
      fVar1 = *(float *)(iVar5 + 8) - *(float *)(*piVar7 + 8);
      fVar3 = *(float *)(iVar5 + 0xc) - *(float *)(*piVar7 + 0xc);
      fVar2 = *(float *)(iVar5 + 0x10) - *(float *)(*piVar7 + 0x10);
      fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
      if ((byte)(64.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 64.0) << 0xe) >> 8)) != 1) {
        *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.3;
        return;
      }
      pcStack_40 = (code *)0x1064bf;
      piStack_3c = piVar7;
      ResetMenu__11CBasePlayer();
      pcStack_40 = (code *)0x0;
      piStack_44 = piVar7 + 0x4e;
      ppiVar9 = &piStack_44;
      __as__7EHANDLEP11CBaseEntity();
    }
  }
LAB_001064cd:
  *(int **)((int)ppiVar9 + -4) = param_1;
  *(undefined4 *)((int)ppiVar9 + -8) = 0x1064d6;
  UTIL_Remove__FP11CBaseEntity();
  return;
}


// Timer_DetpackDisarm__11CBaseEntity  @ 00106200
void Timer_DetpackDisarm__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int **ppiVar6;
  char *pcVar7;
  int *piStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  int *piStack_1c;
  
  iVar2 = *(int *)(*param_1 + 0x178);
  if (iVar2 == 0) {
    piStack_1c = (int *)0x0;
    uStack_20 = 0x106221;
    iVar2 = (*DAT_001755d4)();
    if (iVar2 != 0) goto LAB_0010622a;
    piVar3 = (int *)0x0;
  }
  else {
LAB_0010622a:
    piVar3 = *(int **)(iVar2 + 0xd8);
  }
  iVar2 = *(int *)(*param_1 + 0x170);
  if (iVar2 == 0) {
    piStack_1c = (int *)0x0;
    uStack_20 = 0x10625c;
    iVar2 = (*DAT_001755d4)();
    if (iVar2 != 0) goto LAB_00106265;
    piVar4 = (int *)0x0;
  }
  else {
LAB_00106265:
    piVar4 = *(int **)(iVar2 + 0xd8);
  }
  iVar2 = *(int *)(*piVar4 + 0x178);
  if (iVar2 == 0) {
    piStack_1c = (int *)0x0;
    uStack_20 = 0x106289;
    iVar2 = (*DAT_001755d4)();
    if (iVar2 == 0) {
      piVar5 = (int *)0x0;
      goto LAB_001062a2;
    }
  }
  piVar5 = *(int **)(iVar2 + 0xd8);
LAB_001062a2:
  uStack_20 = 0x1062b3;
  piStack_1c = piVar3;
  iVar2 = (**(code **)(piVar3[0xf2] + 0x88))();
  ppiVar6 = (int **)&stack0xffffffe8;
  if ((iVar2 != 0) &&
     (fVar1 = (float)piVar4[0x43], ppiVar6 = (int **)&stack0xffffffe8,
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    if (birthday == 1) {
      piStack_24 = (int *)(*(int *)(*piVar5 + 0x1b0) + *(int *)(gpGlobals + 0x98));
      piStack_28 = (int *)(*(int *)(*piVar3 + 0x1b0) + *(int *)(gpGlobals + 0x98));
      pcVar7 = "#Detpack_disarm_bday";
    }
    else {
      piStack_24 = (int *)(*(int *)(*piVar3 + 0x1b0) + *(int *)(gpGlobals + 0x98));
      piStack_28 = (int *)(*(int *)(*piVar5 + 0x1b0) + *(int *)(gpGlobals + 0x98));
      pcVar7 = "#Detpack_disarm";
    }
    piStack_1c = (int *)0x0;
    uStack_20 = 0;
    UTIL_ClientPrintAll__FiPCcN41(1,pcVar7);
    *(byte *)((int)piVar3 + 0x8a) = *(byte *)((int)piVar3 + 0x8a) & 0xfe;
    uStack_20 = 0x106354;
    piStack_1c = piVar3;
    TeamFortress_SetSpeed__11CBasePlayer();
    uStack_20 = 1;
    piStack_28 = (int *)0x10635c;
    piStack_24 = piVar3;
    TF_AddFrags__11CBasePlayeri();
    ppiVar6 = &piStack_28;
    piStack_28 = piVar4;
    dremove__FP11CBaseEntity();
  }
  *(int **)((int)ppiVar6 + -4) = param_1;
  *(undefined4 *)((int)ppiVar6 + -8) = 0x10636b;
  dremove__FP11CBaseEntity();
  return;
}


// Timer_DetpackSet__11CBaseEntity  @ 00106120
void Timer_DetpackSet__11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(*param_1 + 0x178);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      piVar3 = (int *)0x0;
      goto LAB_00106152;
    }
  }
  piVar3 = *(int **)(iVar1 + 0xd8);
LAB_00106152:
  piVar3[0x1c] = 0;
  *(byte *)((int)piVar3 + 0x8a) = *(byte *)((int)piVar3 + 0x8a) & 0xfe;
  TeamFortress_SetSpeed__11CBasePlayer(piVar3);
  (**(code **)(*(int *)(piVar3[0x20c] + 0x3c8) + 0x118))(piVar3[0x20c]);
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  piVar2 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                            ("detpack",*piVar3 + 8,&local_10,*(undefined4 *)(*piVar3 + 0x1e8));
  *(float *)(*piVar2 + 0x140) = *gpGlobals + *(float *)(*param_1 + 0x140);
  ClientPrint__FP9entvars_tiPCcN42(*piVar3,1,"#Detpack_finishset",0,0,0,0);
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_FinishedBuilding__11CBaseEntity  @ 00106510
void Timer_FinishedBuilding__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int **ppiVar4;
  int *piStack_24;
  char *pcStack_20;
  int iStack_1c;
  int *piStack_18;
  int iStack_14;
  int *piStack_10;
  
  piStack_10 = *(int **)(*param_1 + 0x178);
  bVar1 = false;
  if (piStack_10 == (int *)0x0) {
LAB_00106535:
    bVar1 = true;
  }
  else {
    iStack_14 = 0x10652e;
    iVar2 = (*DAT_001755d8)();
    if (iVar2 == 0) goto LAB_00106535;
  }
  if (bVar1) {
    piStack_10 = param_1;
    iStack_14 = 0x106544;
    UTIL_Remove__FP11CBaseEntity();
    return;
  }
  iVar2 = *(int *)(*param_1 + 0x178);
  if (iVar2 == 0) {
    piStack_10 = (int *)0x0;
    iStack_14 = 0x106565;
    iVar2 = (*DAT_001755d4)();
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
      goto LAB_00106582;
    }
  }
  piVar3 = *(int **)(iVar2 + 0xd8);
LAB_00106582:
  piStack_10 = (int *)0x64;
  iStack_14 = 0x20;
  piStack_18 = (int *)0x0;
  iStack_1c = 0;
  pcStack_20 = "weapons/building.wav";
  piStack_24 = (int *)0x6;
  EMIT_SOUND_DYN__FP7edict_siPCcffii(*(undefined4 *)(*piVar3 + 0x1e8));
  ppiVar4 = (int **)&stack0xfffffff4;
  if (piVar3[0x1b] == 1) {
    piVar3[0x1b] = 0;
    *(byte *)((int)piVar3 + 0x8a) = *(byte *)((int)piVar3 + 0x8a) & 0xfe;
    iStack_14 = 0x1065be;
    piStack_10 = piVar3;
    TeamFortress_SetSpeed__11CBasePlayer();
    iStack_14 = piVar3[0x20c];
    piStack_18 = (int *)0x1065d3;
    (**(code **)(*(int *)(iStack_14 + 0x3c8) + 0x118))();
    iStack_1c = 0x1065df;
    piStack_18 = piVar3 + 0x4e;
    iStack_1c = __rf__7EHANDLE();
    pcStack_20 = "j";
    (**(code **)(*(int *)(iStack_1c + 0x3c8) + 0xe4))();
    pcStack_20 = (char *)0x0;
    ppiVar4 = &piStack_24;
    piStack_24 = piVar3 + 0x4e;
    __as__7EHANDLEP11CBaseEntity();
  }
  *(int **)((int)ppiVar4 + -4) = param_1;
  *(undefined4 *)((int)ppiVar4 + -8) = 0x1065fe;
  dremove__FP11CBaseEntity();
  return;
}


// Timer_Hallucination__11CBaseEntity  @ 00104b80
void Timer_Hallucination__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  float **ppfVar9;
  short unaff_DI;
  short sVar10;
  longdouble lVar11;
  float *local_64;
  float *local_60;
  float *local_5c;
  float *pfStack_58;
  float fStack_44;
  float *pfStack_40;
  float *pfStack_3c;
  float fStack_38;
  float *pfStack_34;
  float fStack_30;
  float local_2c;
  float *local_28;
  float *local_24;
  float local_20;
  float *local_1c;
  float *local_18;
  float local_14;
  float *local_10;
  float *local_c;
  float local_8;
  
  iVar5 = *(int *)(*param_1 + 0x178);
  if (iVar5 == 0) {
    pfStack_58 = (float *)0x0;
    local_5c = (float *)0x104ba1;
    iVar5 = (*DAT_001755d4)();
    if (iVar5 != 0) goto LAB_00104baa;
    piVar8 = (int *)0x0;
  }
  else {
LAB_00104baa:
    piVar8 = *(int **)(iVar5 + 0xd8);
  }
  local_8 = *(float *)(*param_1 + 0x140) - 2.5;
  *(float *)(*param_1 + 0x140) = local_8;
  if (piVar8[0xb] == 5) {
    local_8 = *(float *)(*param_1 + 0x140) - 2.5;
    *(float *)(*param_1 + 0x140) = local_8;
  }
  if (((*(float *)(*param_1 + 0x140) <= 0.0) || (*(int *)(*piVar8 + 0x150) != 0)) ||
     (piVar8[0x1f] != 0)) {
    *(byte *)((int)piVar8 + 0x89) = *(byte *)((int)piVar8 + 0x89) & 0xbf;
  }
  if (((*(int *)(*piVar8 + 0x150) != 0) || (piVar8[0x1f] != 0)) ||
     ((*(byte *)((int)piVar8 + 0x89) & 0x40) == 0)) {
    pfStack_58 = (float *)param_1;
    local_5c = (float *)0x104c47;
    UTIL_Remove__FP11CBaseEntity();
    return;
  }
  local_8 = *gpGlobals + 0.3;
  *(float *)(*param_1 + 0xe4) = local_8;
  pfStack_58 = (float *)0x14;
  local_5c = (float *)0x0;
  local_60 = (float *)0x104c76;
  uVar6 = (*DAT_00175628)();
  switch(uVar6) {
  case 0:
    pfStack_58 = (float *)0x146d9c;
    local_5c = *(float **)(*piVar8 + 0x1e8);
    local_60 = (float *)0x104ca5;
    (*DAT_00175564)();
    break;
  case 1:
    pfStack_58 = (float *)0x146dc0;
    local_5c = *(float **)(*piVar8 + 0x1e8);
    local_60 = (float *)0x104cc5;
    (*DAT_00175564)();
    local_60 = (float *)0x3f666666;
    local_64 = (float *)0x41200000;
    UTIL_ScreenShakeOne__FP7edict_sfff(*(undefined4 *)(*piVar8 + 0x1e8),0x41400000);
    break;
  case 2:
    pfStack_58 = (float *)(*piVar8 + 0x50);
    local_5c = (float *)0x104cfb;
    UTIL_MakeVectors__FRC6Vector();
    local_5c = (float *)0x43960000;
    local_60 = (float *)0x42c80000;
    local_64 = (float *)0x104d0c;
    lVar11 = (longdouble)(*DAT_0017562c)();
    local_2c = (float)(lVar11 * (longdouble)gpGlobals[10]);
    local_28 = (float *)(float)(lVar11 * (longdouble)gpGlobals[0xb]);
    local_24 = (float *)(float)(lVar11 * (longdouble)gpGlobals[0xc]);
    iVar5 = *piVar8;
    local_18 = (float *)(*(float *)(iVar5 + 0x10) + (float)local_24);
    local_20 = (float)((longdouble)*(float *)(iVar5 + 8) + lVar11 * (longdouble)gpGlobals[10]);
    local_1c = (float *)(float)((longdouble)*(float *)(iVar5 + 0xc) +
                               lVar11 * (longdouble)gpGlobals[0xb]);
    pfStack_58 = (float *)0x42c80000;
    local_5c = (float *)0xc2c80000;
    local_60 = (float *)0x104d78;
    local_14 = local_20;
    local_10 = local_1c;
    local_c = local_18;
    lVar11 = (longdouble)(*DAT_0017562c)();
    local_20 = (float)(lVar11 * (longdouble)gpGlobals[0x10]);
    local_1c = (float *)(float)(lVar11 * (longdouble)gpGlobals[0x11]);
    local_18 = (float *)(float)(lVar11 * (longdouble)gpGlobals[0x12]);
    local_24 = (float *)((float)local_c + (float)local_18);
    local_2c = (float)((longdouble)local_14 + lVar11 * (longdouble)gpGlobals[0x10]);
    local_28 = (float *)(float)((longdouble)(float)local_10 + lVar11 * (longdouble)gpGlobals[0x11]);
    pfStack_58 = *(float **)(*piVar8 + 0x1e8);
    local_5c = (float *)0x0;
    local_60 = (float *)0x17;
    local_64 = (float *)0x1;
    local_14 = local_2c;
    local_10 = local_28;
    local_c = local_24;
    (*DAT_00175578)();
    pfStack_58 = (float *)0x3;
    local_5c = (float *)0x104df0;
    (*DAT_00175580)();
    local_5c = (float *)local_14;
    local_60 = (float *)0x104e00;
    (*DAT_00175594)();
    local_60 = local_10;
    local_64 = (float *)0x104e10;
    (*DAT_00175594)();
    local_64 = local_c;
    (*DAT_00175594)();
    (*DAT_00175588)((int)g_sModelIndexFireball);
    (*DAT_00175580)(0x14);
    (*DAT_00175580)(0xc);
    (*DAT_00175580)(3);
    ppfVar9 = (float **)&stack0xffffffac;
    goto LAB_001054a7;
  case 3:
    pfStack_58 = (float *)(*piVar8 + 0x50);
    local_5c = (float *)0x104e6b;
    UTIL_MakeVectors__FRC6Vector();
    iVar5 = *piVar8;
    local_2c = *(float *)(iVar5 + 8);
    local_28 = *(float **)(iVar5 + 0xc);
    local_24 = *(float **)(iVar5 + 0x10);
    local_5c = (float *)0x43000000;
    local_60 = (float *)0x0;
    local_64 = (float *)0x104e8d;
    lVar11 = (longdouble)(*DAT_0017562c)();
    local_24 = (float *)(float)(lVar11 + (longdouble)(float)local_24);
    local_64 = (float *)0x43000000;
    lVar11 = (longdouble)(*DAT_0017562c)(0xc3000000);
    fStack_38 = (float)(lVar11 * (longdouble)gpGlobals[0x10]);
    pfStack_34 = (float *)(float)(lVar11 * (longdouble)gpGlobals[0x11]);
    fStack_30 = (float)(lVar11 * (longdouble)gpGlobals[0x12]);
    local_24 = (float *)((float)local_24 + fStack_30);
    local_2c = (float)((longdouble)local_2c + lVar11 * (longdouble)gpGlobals[0x10]);
    local_28 = (float *)(float)((longdouble)(float)local_28 + lVar11 * (longdouble)gpGlobals[0x11]);
    iVar5 = *piVar8;
    fVar1 = *(float *)(iVar5 + 0x20);
    fVar2 = *(float *)(iVar5 + 0x24);
    fVar3 = *(float *)(iVar5 + 0x28);
    pfStack_58 = (float *)0x3;
    local_5c = (float *)0x0;
    local_60 = (float *)0x104f22;
    local_14 = local_2c;
    local_10 = local_28;
    local_c = local_24;
    iVar5 = (*DAT_00175628)();
    sVar10 = g_sModelIndexGrenade;
    if (iVar5 != 1) {
      if (iVar5 < 2) {
        sVar10 = g_sModelIndexMirvGrenade;
        if (iVar5 != 0) {
          sVar10 = unaff_DI;
        }
      }
      else {
        sVar10 = g_sModelIndexNapalmGrenade;
        if ((iVar5 != 2) && (sVar10 = g_sModelIndexNailGrenade, iVar5 != 3)) {
          sVar10 = unaff_DI;
        }
      }
    }
    local_5c = (float *)0x104f90;
    pfStack_58 = &local_2c;
    iVar5 = UTIL_PointContents__FRC6Vector();
    if (iVar5 != -2) {
      iVar5 = *piVar8;
      local_20 = *(float *)(iVar5 + 0x74);
      local_1c = *(float **)(iVar5 + 0x78);
      local_18 = *(float **)(iVar5 + 0x7c);
      pfStack_58 = (float *)0x42480000;
      local_5c = (float *)0xc2480000;
      local_60 = (float *)0x104fc1;
      lVar11 = (longdouble)(*DAT_0017562c)();
      local_60 = (float *)(float)(lVar11 + (longdouble)(float)local_1c);
      local_64 = (float *)0x104fcf;
      lVar11 = (longdouble)UTIL_AngleMod__Ff();
      local_1c = (float *)(float)lVar11;
      local_64 = &local_20;
      UTIL_MakeVectors__FRC6Vector();
      lVar11 = (longdouble)(*DAT_0017562c)(0x43480000,0x43c80000);
      lVar11 = lVar11 + (longdouble)SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
      fStack_38 = (float)(lVar11 * (longdouble)gpGlobals[10]);
      pfStack_34 = (float *)(float)(lVar11 * (longdouble)gpGlobals[0xb]);
      fStack_30 = (float)(lVar11 * (longdouble)gpGlobals[0xc]);
      local_64 = &fStack_38;
      pfStack_58 = (float *)0x0;
      local_5c = (float *)(int)sVar10;
      local_60 = (float *)0x0;
      EjectBrass__FRC6VectorT0fii(&local_2c);
    }
    break;
  case 4:
    pfStack_58 = *(float **)(*piVar8 + 0x1e8);
    local_5c = (float *)0x0;
    local_60 = (float *)0x17;
    local_64 = (float *)0x1;
    (*DAT_00175578)();
    pfStack_58 = (float *)0x79;
    local_5c = (float *)0x105052;
    (*DAT_00175580)();
    pfStack_58 = *(float **)(*piVar8 + 0x1e8);
    local_5c = (float *)0x105065;
    pfStack_58 = (float *)(*DAT_001755dc)();
    local_5c = (float *)0x105070;
    (*DAT_00175588)();
    local_5c = (float *)(int)g_sModelIndexPlayerFlame;
    local_60 = (float *)0x10507f;
    (*DAT_00175588)();
    local_60 = (float *)0x5;
    local_64 = (float *)0x105088;
    (*DAT_00175580)();
    local_64 = (float *)0x19;
    goto LAB_001054a0;
  case 5:
    pfStack_58 = (float *)(*piVar8 + 0x74);
    local_5c = (float *)0x10509b;
    UTIL_MakeVectors__FRC6Vector();
    pfVar4 = gpGlobals;
    gpGlobals[0xc] = 0.0;
    fStack_44 = pfVar4[10] * -200.0;
    pfStack_40 = (float *)(pfVar4[0xb] * -200.0);
    pfStack_3c = (float *)(pfVar4[0xc] * -200.0);
    iVar5 = *piVar8;
    fStack_38 = *(float *)(iVar5 + 8) + fStack_44;
    pfStack_34 = (float *)(*(float *)(iVar5 + 0xc) + (float)pfStack_40);
    fStack_30 = *(float *)(iVar5 + 0x10) + (float)pfStack_3c;
    pfStack_58 = (float *)0x42c80000;
    local_5c = (float *)0xc2c80000;
    local_60 = (float *)0x105114;
    local_14 = fStack_38;
    local_10 = pfStack_34;
    local_c = (float *)fStack_30;
    lVar11 = (longdouble)(*DAT_0017562c)();
    local_14 = (float)(lVar11 * (longdouble)gpGlobals[0x10]);
    local_10 = (float *)(float)(lVar11 * (longdouble)gpGlobals[0x11]);
    local_c = (float *)(float)(lVar11 * (longdouble)gpGlobals[0x12]);
    pfStack_3c = (float *)(fStack_30 + (float)local_c);
    fStack_44 = (float)((longdouble)fStack_38 + lVar11 * (longdouble)gpGlobals[0x10]);
    pfStack_40 = (float *)(float)((longdouble)(float)pfStack_34 +
                                 lVar11 * (longdouble)gpGlobals[0x11]);
    fStack_30 = *(float *)(*piVar8 + 0x15c) * 0.8 + (float)pfStack_3c;
    local_5c = &fStack_44;
    pfStack_58 = gpGlobals + 10;
    local_60 = (float *)0x105192;
    fStack_38 = fStack_44;
    pfStack_34 = pfStack_40;
    local_8 = fStack_30;
    UTIL_VecToAngles__FRC6Vector();
    local_20 = fStack_44;
    local_1c = pfStack_40;
    local_18 = pfStack_3c;
    local_60 = (float *)0x40c00000;
    local_64 = (float *)0xc0c00000;
    lVar11 = (longdouble)(*DAT_0017562c)();
    local_1c = (float *)(float)(lVar11 + (longdouble)(float)local_1c);
    iVar5 = UTIL_PointContents__FRC6Vector(&fStack_38);
    if (iVar5 != -2) {
      iVar5 = 0;
      do {
        local_5c = &local_20;
        local_60 = (float *)0x1051dd;
        UTIL_MakeVectors__FRC6Vector();
        fVar1 = (float)(iVar5 * -0x14 + 600);
        fStack_44 = fVar1 * gpGlobals[10];
        pfStack_40 = (float *)(fVar1 * gpGlobals[0xb]);
        pfStack_3c = (float *)(fVar1 * gpGlobals[0xc]);
        local_5c = *(float **)(*piVar8 + 0x1e8);
        local_60 = (float *)0x0;
        local_64 = (float *)0x17;
        local_2c = fStack_44;
        local_28 = pfStack_40;
        local_24 = pfStack_3c;
        (*DAT_00175578)(1);
        local_5c = (float *)0x77;
        local_60 = (float *)0x10524c;
        (*DAT_00175580)();
        local_60 = (float *)fStack_38;
        local_64 = (float *)0x10525c;
        (*DAT_00175594)();
        local_64 = pfStack_34;
        (*DAT_00175594)();
        (*DAT_00175594)(fStack_30);
        (*DAT_00175594)(local_2c);
        (*DAT_00175594)(local_28);
        (*DAT_00175594)(local_24);
        (*DAT_00175588)((int)g_sModelIndexNail);
        local_5c = (float *)0x6;
        local_60 = (float *)0x1052c7;
        (*DAT_00175580)();
        local_5c = *(float **)(*piVar8 + 0x1e8);
        local_60 = (float *)0x1052da;
        uVar7 = (*DAT_001755dc)();
        local_5c = (float *)(uVar7 & 0xff);
        local_60 = (float *)0x1052ea;
        (*DAT_00175580)();
        local_60 = (float *)0x1052f1;
        (*DAT_0017557c)();
        local_60 = (float *)0x41000000;
        local_64 = (float *)0x40800000;
        lVar11 = (longdouble)(*DAT_0017562c)();
        local_1c = (float *)(float)(lVar11 + (longdouble)(float)local_1c);
        lVar11 = (longdouble)(*DAT_0017562c)(0xc1200000,0x41200000);
        fStack_30 = (float)(lVar11 + (longdouble)fStack_30);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 3);
    }
    break;
  case 6:
    iVar5 = *piVar8;
    fStack_44 = *(float *)(iVar5 + 0x74);
    pfStack_40 = *(float **)(iVar5 + 0x78);
    pfStack_3c = *(float **)(iVar5 + 0x7c);
    pfStack_58 = (float *)0x41700000;
    local_5c = (float *)0xc1700000;
    local_60 = (float *)0x105365;
    lVar11 = (longdouble)(*DAT_0017562c)();
    fStack_44 = (float)(lVar11 + (longdouble)fStack_44);
    local_60 = (float *)0x42480000;
    local_64 = (float *)0xc2480000;
    lVar11 = (longdouble)(*DAT_0017562c)();
    pfStack_40 = (float *)(float)(lVar11 + (longdouble)(float)pfStack_40);
    lVar11 = (longdouble)(*DAT_0017562c)(0xc1c80000,0x41c80000);
    pfStack_3c = (float *)(float)(lVar11 + (longdouble)(float)pfStack_3c);
    UTIL_VecToAngles__FRC6Vector(&fStack_38,&fStack_44);
    pfVar4 = DAT_00154ce4;
    if ((int)DAT_00154ce4 < 0) {
      return;
    }
    local_5c = (float *)0x146ddf;
    local_60 = *(float **)(*piVar8 + 0x1e8);
    local_64 = (float *)0x1053cc;
    (*DAT_00175564)();
    local_5c = *(float **)(*piVar8 + 0x1e8);
    local_60 = (float *)0x0;
    local_64 = (float *)0x17;
    (*DAT_00175578)(1);
    local_5c = (float *)0x7e;
    local_60 = (float *)0x1053f1;
    (*DAT_00175580)();
    local_60 = *(float **)(*piVar8 + 8);
    local_64 = (float *)0x105403;
    (*DAT_00175594)();
    local_64 = *(float **)(*piVar8 + 0xc);
    (*DAT_00175594)();
    (*DAT_00175594)(*(undefined4 *)(*piVar8 + 0x10));
    local_8 = fStack_44 * 10.0;
    (*DAT_00175594)(local_8);
    local_8 = (float)pfStack_40 * 10.0;
    (*DAT_00175594)(local_8);
    local_8 = (float)pfStack_3c * 10.0;
    (*DAT_00175594)(local_8);
    (*DAT_00175594)(0x42a00000);
    local_5c = (float *)0x42a00000;
    local_60 = (float *)0x105496;
    (*DAT_00175594)();
    local_60 = (float *)0x6;
    local_64 = (float *)0x10549f;
    (*DAT_00175580)();
    local_64 = pfVar4;
LAB_001054a0:
    ppfVar9 = &local_64;
    (*DAT_00175580)();
LAB_001054a7:
    *(undefined4 *)((int)ppfVar9 + -4) = 0x1054ae;
    (*DAT_0017557c)();
  }
  return;
}


// Timer_HealthRot__11CBaseEntity  @ 00104a70
void Timer_HealthRot__11CBaseEntity(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(int *)(*param_1 + 0x178);
  if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar3 + 0xd8);
  }
  iVar3 = *piVar4;
  if (*(float *)(iVar3 + 0x140) <= *(float *)(iVar3 + 400)) {
    *(byte *)((int)piVar4 + 0x8e) = *(byte *)((int)piVar4 + 0x8e) & 0xfe;
    bVar2 = false;
    if ((*(int *)(*param_1 + 0x170) == 0) ||
       (iVar3 = (*DAT_001755d8)(*(int *)(*param_1 + 0x170)), iVar3 == 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      iVar3 = *(int *)(*param_1 + 0x170);
      if ((iVar3 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0xd8);
      }
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0xb8))(iVar3);
      return;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    iVar3 = *param_1;
    fVar1 = *gpGlobals;
  }
  else {
    *(float *)(iVar3 + 0x140) = *(float *)(iVar3 + 0x140) - 1.0;
    iVar3 = *param_1;
    fVar1 = *gpGlobals + 1.0;
  }
  *(float *)(iVar3 + 0xe4) = fVar1;
  return;
}


// Timer_Infection__11CBaseEntity  @ 00104640
void Timer_Infection__11CBaseEntity(int *param_1)

{
  code *pcVar1;
  float *pfVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  int *piVar10;
  bool bVar11;
  undefined2 in_FPUControlWord;
  int aiStackY_d4 [10];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [16];
  float fStack_44;
  int iStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_8;
  undefined2 uStack_6;
  
  iVar4 = *(int *)(*param_1 + 0x178);
  if (iVar4 == 0) {
    iVar4 = (*DAT_001755d4)(0);
    if (iVar4 != 0) goto LAB_0010466d;
    piVar7 = (int *)0x0;
  }
  else {
LAB_0010466d:
    piVar7 = *(int **)(iVar4 + 0xd8);
  }
  iVar4 = *(int *)(*param_1 + 0x170);
  if (iVar4 == 0) {
    iVar4 = (*DAT_001755d4)(0);
    if (iVar4 == 0) {
      puVar8 = (undefined4 *)0x0;
      goto LAB_001046b2;
    }
  }
  puVar8 = *(undefined4 **)(iVar4 + 0xd8);
LAB_001046b2:
  bVar11 = false;
  uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
  if ((((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) && (piVar7[0x48] == puVar8[0x48])) {
    bVar11 = piVar7[0x48] != 0;
  }
  if (*gpGlobals < (float)piVar7[0xe8]) {
    bVar11 = true;
  }
  if (((*(byte *)(piVar7 + 0x22) & 0x10) == 0) || (piVar7[0xb] == 5)) {
    bVar11 = true;
  }
  if (bVar11) {
    *(byte *)(piVar7 + 0x22) = *(byte *)(piVar7 + 0x22) & 0xef;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(float *)(*param_1 + 0xe4) = *gpGlobals;
  }
  else {
    uStack_1c = *(undefined4 *)(*piVar7 + 8);
    uStack_18 = *(undefined4 *)(*piVar7 + 0xc);
    uStack_14 = *(undefined4 *)(*piVar7 + 0x10);
    piVar10 = (int *)0x0;
    puVar3 = &stack0xffffff58;
LAB_001049d2:
    puVar9 = puVar3;
    *(undefined4 *)(puVar9 + -4) = 0x43000000;
    *(undefined4 **)(puVar9 + -8) = &uStack_1c;
    *(int **)(puVar9 + -0xc) = piVar10;
    *(undefined4 *)(puVar9 + -0x10) = 0x1049e1;
    piVar10 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar10 != (int *)0x0) {
      iVar4 = piVar10[0xf2];
      *(int **)(puVar9 + -4) = piVar10;
      pcVar1 = *(code **)(iVar4 + 0x28);
      *(undefined4 *)(puVar9 + -8) = 0x1047ac;
      iVar4 = (*pcVar1)();
      puVar3 = puVar9;
      if (iVar4 == 2) {
        iVar4 = piVar10[0xf2];
        *(int **)(puVar9 + -4) = piVar10;
        pcVar1 = *(code **)(iVar4 + 0x88);
        *(undefined4 *)(puVar9 + -8) = 0x1047c7;
        iVar4 = (*pcVar1)();
        if ((((iVar4 != 0) && (piVar10[0xb] != 0)) && ((*(byte *)(piVar10 + 0x22) & 0x10) == 0)) &&
           (piVar10[0xb] != 5)) {
          uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
          if (((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) {
            *(undefined4 **)(puVar9 + -4) = puVar8;
            *(int **)(puVar9 + -8) = piVar10;
            *(undefined4 *)(puVar9 + -0xc) = 0x10481f;
            iVar4 = IsAlly__11CBaseEntityP11CBaseEntity();
            if (iVar4 != 0) goto LAB_001049d2;
          }
          iVar4 = piVar10[0xf2];
          *(undefined4 **)(puVar9 + -4) = &uStack_1c;
          *(int **)(puVar9 + -8) = piVar10;
          *(undefined4 **)(puVar9 + -0xc) = &uStack_60;
          pcVar1 = *(code **)(iVar4 + 0xd0);
          *(undefined4 *)(puVar9 + -0x10) = 0x104843;
          (*pcVar1)();
          *(undefined1 **)(puVar9 + -0x10) = auStack_54;
          *(undefined4 *)(puVar9 + -0x14) = *(undefined4 *)(*param_1 + 0x1e8);
          *(undefined4 *)(puVar9 + -0x18) = 0;
          *(undefined4 **)(puVar9 + -0x1c) = &uStack_60;
          *(undefined4 **)(puVar9 + -0x20) = &uStack_1c;
          *(undefined4 *)(puVar9 + -0x24) = 0x104862;
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
          if (((byte)(1.0 < fStack_44 | (byte)((ushort)((ushort)NAN(fStack_44) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fStack_44 == 1.0) << 0xe) >> 8)) == 0x40) ||
             (puVar3 = puVar9 + -4, iStack_24 == *(int *)(*piVar10 + 0x1e8))) {
            uVar6 = *(undefined4 *)(*piVar10 + 0x1e8);
            *(undefined4 *)(puVar9 + -8) = 100;
            *(undefined4 *)(puVar9 + -0xc) = 0;
            *(undefined4 *)(puVar9 + -0x10) = 0x3f4ccccd;
            *(undefined4 *)(puVar9 + -0x14) = 0x3f800000;
            *(char **)(puVar9 + -0x18) = "player/death2.wav";
            *(undefined4 *)(puVar9 + -0x1c) = 2;
            *(undefined4 *)(puVar9 + -0x20) = uVar6;
            *(undefined4 *)(puVar9 + -0x24) = 0x1048aa;
            EMIT_SOUND_DYN__FP7edict_siPCcffii();
            *(byte *)(piVar10 + 0x22) = *(byte *)(piVar10 + 0x22) | 0x10;
            *(undefined4 *)(puVar9 + -8) = 2;
            *(int **)(puVar9 + -0xc) = piVar10;
            *(undefined4 *)(puVar9 + -0x10) = 0x1048bc;
            piVar5 = (int *)CreateTimer__11CBaseEntityi();
            pfVar2 = gpGlobals;
            *(float *)(*piVar5 + 0xe4) = *gpGlobals + 2.0;
            piVar5[3] = -0x10000;
            piVar5[4] = (int)Timer_Infection__11CBaseEntity;
            *(undefined4 *)(*piVar5 + 0x170) = *(undefined4 *)(*param_1 + 0x170);
            piVar10[0x4a] = piVar7[0x48];
            *(undefined4 *)(puVar9 + -0x10) = 0;
            *(undefined4 *)(puVar9 + -0x14) = 0;
            *(undefined4 *)(puVar9 + -0x18) = 0;
            *(int *)(puVar9 + -0x1c) = *(int *)(*piVar7 + 0x1b0) + (int)pfVar2[0x26];
            *(char **)(puVar9 + -0x20) = "#Medic_infected";
            *(undefined4 *)(puVar9 + -0x24) = 1;
            *(int *)(puVar9 + -0x28) = *piVar10;
            *(undefined4 *)(puVar9 + -0x2c) = 0x104941;
            ClientPrint__FP9entvars_tiPCcN42();
            *(undefined4 *)(puVar9 + -8) = 0;
            *(undefined4 *)(puVar9 + -0xc) = 0;
            *(undefined4 *)(puVar9 + -0x10) = 0;
            *(int *)(puVar9 + -0x14) = *(int *)(*piVar10 + 0x1b0) + (int)gpGlobals[0x26];
            *(char **)(puVar9 + -0x18) = "#Medic_infect";
            *(undefined4 *)(puVar9 + -0x1c) = 1;
            *(int *)(puVar9 + -0x20) = *piVar7;
            *(undefined4 *)(puVar9 + -0x24) = 0x10496e;
            ClientPrint__FP9entvars_tiPCcN42();
            *(undefined4 *)(puVar9 + -8) = *(undefined4 *)(*piVar10 + 0x1e8);
            *(undefined4 *)(puVar9 + -0xc) = 0x104982;
            uVar6 = (*DAT_00175684)();
            *(undefined4 *)(puVar9 + -0xc) = uVar6;
            *(int *)(puVar9 + -0x10) = *(int *)(*piVar10 + 0x1b0) + (int)gpGlobals[0x26];
            *(undefined4 *)(puVar9 + -0x14) = *(undefined4 *)(*piVar7 + 0x1e8);
            *(undefined4 *)(puVar9 + -0x18) = 0x1049aa;
            uVar6 = (*DAT_00175684)();
            *(undefined4 *)(puVar9 + -0x14) = uVar6;
            *(int *)(puVar9 + -0x18) = *(int *)(*piVar7 + 0x1b0) + (int)gpGlobals[0x26];
            *(char **)(puVar9 + -0x1c) = "\"%s<%i>\" passed on the infection to \"%s<%i>\".\n";
            *(undefined4 *)(puVar9 + -0x20) = 0x1049cf;
            UTIL_LogPrintf__FPce();
            puVar3 = puVar9 + -4;
          }
        }
      }
      goto LAB_001049d2;
    }
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 3.0;
    uStack_60 = *(undefined4 *)(*piVar7 + 8);
    uStack_5c = *(undefined4 *)(*piVar7 + 0xc);
    uStack_58 = *(undefined4 *)(*piVar7 + 0x10);
    *(undefined4 *)(puVar9 + -4) = 0x41000000;
    iVar4 = piVar7[0xf2];
    *(int **)(puVar9 + -8) = piVar7;
    pcVar1 = *(code **)(iVar4 + 0x40);
    *(undefined4 *)(puVar9 + -0xc) = 0x104a31;
    uVar6 = (*pcVar1)();
    *(undefined4 *)(puVar9 + -8) = uVar6;
    *(undefined4 **)(puVar9 + -0xc) = &uStack_60;
    *(code **)(puVar9 + -0x10) = FUN_00104a40;
    SpawnBlood__FG6Vectorif();
    iVar4 = piVar7[0xf2];
    *(undefined4 *)(puVar9 + -0x10) = 0x8010000;
    *(undefined4 *)(puVar9 + -0x14) = 0x41000000;
    *(undefined4 *)(puVar9 + -0x18) = *puVar8;
    *(int *)(puVar9 + -0x1c) = *param_1;
    *(int **)(puVar9 + -0x20) = piVar7;
    pcVar1 = *(code **)(iVar4 + 0x34);
    *(undefined4 *)(puVar9 + -0x24) = 0x104a62;
    (*pcVar1)();
  }
  return;
}


// Timer_Regeneration__11CBaseEntity  @ 00105550
void Timer_Regeneration__11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*param_1 + 0x178);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_00105582;
    }
  }
  piVar2 = *(int **)(iVar1 + 0xd8);
LAB_00105582:
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 3.0;
  iVar1 = *piVar2;
  if (*(float *)(iVar1 + 0x140) < *(float *)(iVar1 + 400)) {
    *(float *)(iVar1 + 0x140) = *(float *)(iVar1 + 0x140) + 2.0;
    iVar1 = *piVar2;
    if (*(float *)(iVar1 + 400) < *(float *)(iVar1 + 0x140)) {
      *(undefined4 *)(iVar1 + 0x140) = *(undefined4 *)(iVar1 + 400);
    }
  }
  return;
}


// Timer_SpyUndercoverThink__11CBaseEntity  @ 00106610
void Timer_SpyUndercoverThink__11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*param_1 + 0x178);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto LAB_00106642;
    }
  }
  puVar2 = *(undefined4 **)(iVar1 + 0xd8);
LAB_00106642:
  if (puVar2[0x1a] == 2) {
    puVar2[99] = *gpGlobals + 10.0;
    if (*(int *)(*param_1 + 0xf0) != 0) {
      uVar3 = UTIL_VarArgs__FPce(&DAT_00148175,
                                 *(undefined4 *)(sClassNames + *(int *)(*param_1 + 0xf0) * 4),0,0,0)
      ;
      ClientPrint__FP9entvars_tiPCcN42(*puVar2,1,"#Disguise_asclass",uVar3);
      puVar2[0x76] = *(undefined4 *)(*param_1 + 0xf0);
    }
    if (param_1[0x48] != 0) {
      uVar3 = UTIL_dtos1__Fi(param_1[0x48],0,0,0);
      ClientPrint__FP9entvars_tiPCcN42(*puVar2,1,"#Disguise_asteam",uVar3);
      puVar2[0x75] = param_1[0x48];
    }
    ClientPrint__FP9entvars_tiPCcN42(*puVar2,4,"#Disguise_now",0,0,0,0);
    puVar2[0x1a] = 1;
    TeamFortress_SpyCalcName__11CBasePlayer(puVar2);
    Spy_DisguiseExternalWeaponModel__11CBasePlayer(puVar2);
    TeamFortress_SetSkin__11CBasePlayer(puVar2);
  }
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_Tranquilisation__11CBaseEntity  @ 001054c0
void Timer_Tranquilisation__11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(*param_1 + 0x178);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto LAB_001054f2;
    }
  }
  puVar2 = *(undefined4 **)(iVar1 + 0xd8);
LAB_001054f2:
  ClientPrint__FP9entvars_tiPCcN42(*puVar2,1,"#Tranq_finished",0,0,0,0);
  *(byte *)((int)puVar2 + 0x89) = *(byte *)((int)puVar2 + 0x89) & 0x7f;
  TeamFortress_SetSpeed__11CBasePlayer(puVar2);
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  return;
}


