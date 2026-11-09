// CD_Command_f  @ 0020f370
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CD_Command_f(void)

{
  _func_int_varargs *p_Var1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
                    /* Unresolved local var: char * command@[???]
                       Unresolved local var: int ret@[???]
                       Unresolved local var: int n@[???] */
  iVar3 = Cmd_Argc();
  if (1 < iVar3) {
    pcVar4 = Cmd_Argv(1);
    iVar3 = strcasecmp(pcVar4,"on");
    if (iVar3 == 0) {
      g_CDAudio.m_bEnabled = true;
      return;
    }
    iVar3 = strcasecmp(pcVar4,"off");
    if (iVar3 == 0) {
      if (g_CDAudio.m_bIsPlaying != false) {
        (*thread->_vptr_IThread[4])(thread,CCDAudio::_Stop,0,0,0);
      }
      g_CDAudio.m_bEnabled = false;
      return;
    }
    iVar3 = strcasecmp(pcVar4,"reset");
    if (iVar3 == 0) {
      g_CDAudio.m_bEnabled = true;
      if (g_CDAudio.m_bIsPlaying != false) {
        (*thread->_vptr_IThread[4])(thread,CCDAudio::_Stop,0,0,0);
      }
      piVar5 = g_CDAudio.m_rgRemapCD;
      iVar3 = 0;
      iVar7 = 1;
      iVar8 = 2;
      iVar9 = 3;
      do {
        *piVar5 = iVar3;
        piVar5[1] = iVar7;
        piVar5[2] = iVar8;
        piVar5[3] = iVar9;
        piVar5 = piVar5 + 4;
        iVar3 = iVar3 + 4;
        iVar7 = iVar7 + 4;
        iVar8 = iVar8 + 4;
        iVar9 = iVar9 + 4;
      } while ((_MP3_AUDIO_STATE *)piVar5 != &g_CDAudio.m_MP3);
      (*thread->_vptr_IThread[4])(thread,CCDAudio::_GetAudioDiskInfo,0,0,0);
    }
    else {
      iVar3 = strcasecmp(pcVar4,"remap");
      if (iVar3 == 0) {
        iVar3 = Cmd_Argc();
        if (2 < iVar3) {
          iVar7 = 1;
          do {
            iVar8 = iVar7 + 1;
            pcVar4 = Cmd_Argv(iVar8);
            lVar6 = strtol(pcVar4,(char **)0x0,10);
            g_CDAudio.m_rgRemapCD[iVar7] = lVar6;
            iVar7 = iVar8;
          } while (iVar8 != iVar3 + -1);
        }
      }
      else {
        iVar3 = strcasecmp(pcVar4,"close");
        if (iVar3 == 0) {
          (*thread->_vptr_IThread[4])(thread,CCDAudio::_CloseDoor,0,0,0);
        }
        else {
          iVar3 = strcasecmp(pcVar4,"mp3info");
          if (iVar3 == 0) {
            Con_Printf("Current MP3 Title: %s\n",0x969233);
            Con_Printf("Current MP3 Track: %i\n",g_CDAudio.m_MP3.tracknum);
            Con_Printf("Current MP3 Volume: %i\n",(double)g_CDAudio.m_MP3.volume);
          }
          else {
            iVar3 = Cmd_Argc();
            if ((iVar3 < 3) || (iVar3 = strcasecmp(pcVar4,"mp3track"), iVar3 != 0)) {
              iVar3 = strcasecmp(pcVar4,"play");
              if (iVar3 == 0) {
                p_Var1 = g_CDAudio.super_ICDAudio._vptr_ICDAudio[2];
                pcVar4 = Cmd_Argv(2);
                lVar6 = strtol(pcVar4,(char **)0x0,10);
                (*p_Var1)(&g_CDAudio,lVar6,0);
              }
              else {
                iVar3 = strcasecmp(pcVar4,"playfile");
                if (iVar3 == 0) {
                  p_Var1 = g_CDAudio.super_ICDAudio._vptr_ICDAudio[3];
                  pcVar4 = Cmd_Argv(2);
                  (*p_Var1)(&g_CDAudio,pcVar4,0);
                }
                else {
                  iVar3 = strcasecmp(pcVar4,"loop");
                  if (iVar3 == 0) {
                    p_Var1 = g_CDAudio.super_ICDAudio._vptr_ICDAudio[2];
                    pcVar4 = Cmd_Argv(2);
                    lVar6 = strtol(pcVar4,(char **)0x0,10);
                    (*p_Var1)(&g_CDAudio,lVar6,1);
                  }
                  else {
                    iVar3 = strcasecmp(pcVar4,"loopfile");
                    if (iVar3 == 0) {
                      p_Var1 = g_CDAudio.super_ICDAudio._vptr_ICDAudio[3];
                      pcVar4 = Cmd_Argv(2);
                      (*p_Var1)(&g_CDAudio,pcVar4,1);
                    }
                    else {
                      iVar3 = strcasecmp(pcVar4,"stop");
                      if (iVar3 == 0) {
                        CCDAudio::Stop(&g_CDAudio);
                      }
                      else {
                        iVar3 = strcasecmp(pcVar4,"fadeout");
                        if (iVar3 == 0) {
                          CCDAudio::FadeOut(&g_CDAudio);
                        }
                        else {
                          iVar3 = strcasecmp(pcVar4,"pause");
                          if (iVar3 == 0) {
                            (*g_CDAudio.super_ICDAudio._vptr_ICDAudio[4])(&g_CDAudio);
                          }
                          else {
                            iVar3 = strcasecmp(pcVar4,"resume");
                            if (iVar3 == 0) {
                              (*g_CDAudio.super_ICDAudio._vptr_ICDAudio[5])(&g_CDAudio);
                            }
                            else {
                              iVar3 = strcasecmp(pcVar4,"eject");
                              if (iVar3 == 0) {
                                if (g_CDAudio.m_bIsPlaying != false) {
                                  CCDAudio::Stop(&g_CDAudio);
                                }
                                CCDAudio::Eject(&g_CDAudio);
                                g_CDAudio.m_bIsCDValid = false;
                              }
                              else {
                                iVar3 = strcasecmp(pcVar4,"info");
                                if (iVar3 == 0) {
                                  Con_Printf("%u tracks\n",g_iMP3NumTracks + -1);
                                  if (g_CDAudio.m_bIsPlaying == false) {
                                    if (g_CDAudio.m_bWasPlaying != false) {
                                      pcVar4 = "looping";
                                      if (g_CDAudio.m_bIsLooping == false) {
                                        pcVar4 = "playing";
                                      }
                                      Con_Printf("Paused %s track %u\n",pcVar4,
                                                 g_CDAudio.m_nPlayTrack);
                                    }
                                  }
                                  else {
                                    pcVar4 = "looping";
                                    if (g_CDAudio.m_bIsLooping == false) {
                                      pcVar4 = "playing";
                                    }
                                    Con_Printf("Currently %s track %u\n",pcVar4,
                                               g_CDAudio.m_nPlayTrack);
                                  }
                                  Con_Printf("Volume is %f\n",(double)g_CDAudio.m_flVolume);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              pcVar4 = Cmd_Argv(2);
              lVar6 = strtol(pcVar4,(char **)0x0,10);
              bVar2 = CCDAudio::MP3_PlayTrack(&g_CDAudio,lVar6 + 1,false);
              if (bVar2) {
                g_CDAudio.m_dStartTime._0_4_ = 0;
                g_CDAudio.m_dStartTime._4_4_ = 0;
                g_CDAudio.m_dPauseTime._0_4_ = 0;
                g_CDAudio.m_flPlayTime = 0.0;
                g_CDAudio.m_dPauseTime._4_4_ = 0;
                g_CDAudio.m_bIsLooping = false;
                g_CDAudio.m_bIsPlaying = true;
                g_CDAudio.m_nPlayTrack = lVar6 + 1;
              }
            }
          }
        }
      }
    }
  }
  return;
}


