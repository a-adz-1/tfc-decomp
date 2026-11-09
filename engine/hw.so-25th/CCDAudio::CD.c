// CCDAudio::CD_f  @ 001bed70
/* DWARF original prototype: void CD_f(CCDAudio * this) */

void __thiscall CCDAudio::CD_f(CCDAudio *this)

{
  float fVar1;
  HSTREAM_conflict p_Var2;
  bool bVar3;
  CCDAudio *in_EAX;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  _func_int_varargs *p_Var9;
  int *piVar10;
  IThread *pIVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  int local_20;
  
                    /* Unresolved local var: char * command@[???]
                       Unresolved local var: int ret@[???]
                       Unresolved local var: int n@[???] */
  pcVar4 = Cmd_Argv(1);
  iVar5 = strcasecmp(pcVar4,"on");
  if (iVar5 == 0) {
    in_EAX->m_bEnabled = true;
    return;
  }
  iVar5 = strcasecmp(pcVar4,"off");
  if (iVar5 == 0) {
    if (in_EAX->m_bIsPlaying != false) {
      (*thread->_vptr_IThread[4])(thread,_Stop,0,0,0);
    }
    in_EAX->m_bEnabled = false;
    return;
  }
  iVar5 = strcasecmp(pcVar4,"reset");
  if (iVar5 == 0) {
    in_EAX->m_bEnabled = true;
    if (in_EAX->m_bIsPlaying != false) {
      (*thread->_vptr_IThread[4])(thread,_Stop,0,0,0);
    }
    uVar6 = -(((uint)in_EAX & 0xf) >> 2) & 3;
    if (uVar6 == 0) {
      iVar12 = 100;
      uVar8 = 0x19;
      iVar13 = 100;
      iVar5 = 100;
      local_20 = 0;
    }
    else {
      in_EAX->m_rgRemapCD[0] = 0;
      if (uVar6 == 1) {
        iVar5 = 99;
        local_20 = 1;
      }
      else {
        in_EAX->m_rgRemapCD[1] = 1;
        if (uVar6 == 2) {
          iVar5 = 0x62;
          local_20 = 2;
        }
        else {
          in_EAX->m_rgRemapCD[2] = 2;
          iVar5 = 0x61;
          local_20 = 3;
        }
      }
      iVar12 = 0x60;
      iVar13 = 100 - uVar6;
      uVar8 = 0x18;
    }
    iVar15 = local_20 + 1;
    iVar16 = local_20 + 2;
    iVar17 = local_20 + 3;
    piVar10 = in_EAX->m_rgRemapCD + uVar6;
    uVar6 = 0;
    iVar14 = local_20;
    do {
      uVar6 = uVar6 + 1;
      *piVar10 = iVar14;
      piVar10[1] = iVar15;
      piVar10[2] = iVar16;
      piVar10[3] = iVar17;
      piVar10 = piVar10 + 4;
      iVar14 = iVar14 + 4;
      iVar15 = iVar15 + 4;
      iVar16 = iVar16 + 4;
      iVar17 = iVar17 + 4;
    } while (uVar6 < uVar8);
    local_20 = local_20 + iVar12;
    if (iVar13 != iVar12) {
      in_EAX->m_rgRemapCD[local_20] = local_20;
      if (iVar5 - iVar12 != 1) {
        in_EAX->m_rgRemapCD[local_20 + 1] = local_20 + 1;
        if (iVar5 - iVar12 != 2) {
          in_EAX->m_rgRemapCD[local_20 + 2] = local_20 + 2;
        }
      }
    }
    (*thread->_vptr_IThread[4])(thread,_GetAudioDiskInfo,0,0,0);
    return;
  }
  iVar5 = strcasecmp(pcVar4,"remap");
  if (iVar5 == 0) {
    iVar5 = Cmd_Argc();
    if (iVar5 < 3) {
      return;
    }
    iVar12 = 1;
    do {
      iVar13 = iVar12 + 1;
      pcVar4 = Cmd_Argv(iVar13);
      lVar7 = strtol(pcVar4,(char **)0x0,10);
      in_EAX->m_rgRemapCD[iVar12] = lVar7;
      iVar12 = iVar13;
    } while (iVar13 != iVar5 + -1);
    return;
  }
  iVar5 = strcasecmp(pcVar4,"close");
  if (iVar5 == 0) {
    (*thread->_vptr_IThread[4])(thread,_CloseDoor,0,0,0);
    return;
  }
  iVar5 = strcasecmp(pcVar4,"mp3info");
  if (iVar5 == 0) {
    Con_Printf("Current MP3 Title: %s\n",(in_EAX->m_MP3).trackname);
    Con_Printf("Current MP3 Track: %i\n",(in_EAX->m_MP3).tracknum);
    Con_Printf("Current MP3 Volume: %i\n",(double)(in_EAX->m_MP3).volume);
    return;
  }
  iVar5 = Cmd_Argc();
  if ((2 < iVar5) && (iVar5 = strcasecmp(pcVar4,"mp3track"), iVar5 == 0)) {
    pcVar4 = Cmd_Argv(2);
    lVar7 = strtol(pcVar4,(char **)0x0,10);
    iVar5 = lVar7 + 1;
    if (iVar5 < 2) {
      return;
    }
    if (g_iMP3NumTracks <= iVar5) {
      return;
    }
    if ((in_EAX->m_bIsPrimed == false) && (bVar3 = MP3_InitStream(in_EAX,iVar5,false), !bVar3)) {
      return;
    }
    p_Var2 = MP3stream;
    in_EAX->m_bIsPrimed = false;
    if (p_Var2 != (HSTREAM_conflict)0x0) {
      AIL_start_stream(p_Var2);
    }
    (in_EAX->m_MP3).inuse = true;
    in_EAX->m_flPlayTime = 0.0;
    fVar1 = in_EAX->m_flMP3Volume;
    (in_EAX->m_MP3).playing = true;
    (in_EAX->m_MP3).tracknum = iVar5;
    (in_EAX->m_MP3).looping = false;
    *(undefined4 *)&in_EAX->m_dStartTime = 0;
    *(undefined4 *)((int)&in_EAX->m_dStartTime + 4) = 0;
    *(undefined4 *)&in_EAX->m_dPauseTime = 0;
    *(undefined4 *)((int)&in_EAX->m_dPauseTime + 4) = 0;
    in_EAX->m_bIsLooping = false;
    in_EAX->m_nPlayTrack = iVar5;
    in_EAX->m_bIsPlaying = true;
    if ((fVar1 == 0.0) && (bVar3 = in_EAX->m_bEnabled, bVar3 != false)) {
      if (MP3stream != (HSTREAM_conflict)0x0) {
        AIL_pause_stream(MP3stream,1);
        bVar3 = in_EAX->m_bIsPlaying;
      }
      in_EAX->m_bWasPlaying = bVar3;
      in_EAX->m_szPendingPlayFilename[0] = '\0';
    }
    in_EAX->m_flPlayTime = 0.0;
    *(undefined4 *)&in_EAX->m_dStartTime = 0;
    *(undefined4 *)((int)&in_EAX->m_dStartTime + 4) = 0;
    *(undefined4 *)&in_EAX->m_dPauseTime = 0;
    *(undefined4 *)((int)&in_EAX->m_dPauseTime + 4) = 0;
    in_EAX->m_bIsLooping = false;
    in_EAX->m_nPlayTrack = iVar5;
    in_EAX->m_bIsPlaying = true;
    return;
  }
  iVar5 = strcasecmp(pcVar4,"play");
  if (iVar5 == 0) {
    p_Var9 = (in_EAX->super_ICDAudio)._vptr_ICDAudio[2];
    pcVar4 = Cmd_Argv(2);
    lVar7 = strtol(pcVar4,(char **)0x0,10);
    pIVar11 = thread;
    if (p_Var9 == Play) {
      *(undefined4 *)&in_EAX->m_dFadeOutTime = 0;
      *(undefined4 *)((int)&in_EAX->m_dFadeOutTime + 4) = 0;
      p_Var9 = pIVar11->_vptr_IThread[4];
      uVar18 = 0;
LAB_001bf31e:
      (*p_Var9)(pIVar11,_Play,0,lVar7,uVar18);
      return;
    }
  }
  else {
    iVar5 = strcasecmp(pcVar4,"playfile");
    if (iVar5 != 0) {
      iVar5 = strcasecmp(pcVar4,"loop");
      if (iVar5 == 0) {
        p_Var9 = (in_EAX->super_ICDAudio)._vptr_ICDAudio[2];
        pcVar4 = Cmd_Argv(2);
        lVar7 = strtol(pcVar4,(char **)0x0,10);
        pIVar11 = thread;
        if (p_Var9 == Play) {
          *(undefined4 *)&in_EAX->m_dFadeOutTime = 0;
          *(undefined4 *)((int)&in_EAX->m_dFadeOutTime + 4) = 0;
          p_Var9 = pIVar11->_vptr_IThread[4];
          uVar18 = 1;
          goto LAB_001bf31e;
        }
      }
      else {
        iVar5 = strcasecmp(pcVar4,"loopfile");
        if (iVar5 != 0) {
          iVar5 = strcasecmp(pcVar4,"stop");
          if (iVar5 == 0) {
            (*thread->_vptr_IThread[4])(thread,_Stop,0,0,0);
            return;
          }
          iVar5 = strcasecmp(pcVar4,"fadeout");
          pIVar11 = thread;
          if (iVar5 == 0) {
            if (in_EAX->m_bIsPlaying == false) {
              return;
            }
            in_EAX->m_dFadeOutTime = realtime + (double)MP3FadeTime.value;
            (*pIVar11->_vptr_IThread[4])(pIVar11,_CDUpdate,0,0,0);
            return;
          }
          iVar5 = strcasecmp(pcVar4,"pause");
          if (iVar5 == 0) {
            (*(in_EAX->super_ICDAudio)._vptr_ICDAudio[4])();
            return;
          }
          iVar5 = strcasecmp(pcVar4,"resume");
          if (iVar5 != 0) {
            iVar5 = strcasecmp(pcVar4,"eject");
            if (iVar5 == 0) {
              if (in_EAX->m_bIsPlaying != false) {
                (*thread->_vptr_IThread[4])(thread,_Stop,0,0,0);
              }
              (*thread->_vptr_IThread[4])(thread,_Eject,0,0,0);
              in_EAX->m_bIsCDValid = false;
              return;
            }
            iVar5 = strcasecmp(pcVar4,"info");
            if (iVar5 != 0) {
              return;
            }
            Con_Printf("%u tracks\n",g_iMP3NumTracks + -1);
            if (in_EAX->m_bIsPlaying == false) {
              if (in_EAX->m_bWasPlaying != false) {
                pcVar4 = "playing";
                if (in_EAX->m_bIsLooping != false) {
                  pcVar4 = "looping";
                }
                Con_Printf("Paused %s track %u\n",pcVar4,in_EAX->m_nPlayTrack);
              }
            }
            else {
              pcVar4 = "playing";
              if (in_EAX->m_bIsLooping != false) {
                pcVar4 = "looping";
              }
              Con_Printf("Currently %s track %u\n",pcVar4,in_EAX->m_nPlayTrack);
            }
            Con_Printf("Volume is %f\n",(double)in_EAX->m_flVolume);
            return;
          }
          (*(in_EAX->super_ICDAudio)._vptr_ICDAudio[5])();
          return;
        }
        p_Var9 = (in_EAX->super_ICDAudio)._vptr_ICDAudio[3];
        pcVar4 = Cmd_Argv(2);
        if (p_Var9 == PlayFile) {
          *(undefined4 *)&in_EAX->m_dFadeOutTime = 0;
          *(undefined4 *)((int)&in_EAX->m_dFadeOutTime + 4) = 0;
          strncpy(in_EAX->m_szPendingPlayFilename,pcVar4,0x200);
          p_Var9 = thread->_vptr_IThread[4];
          uVar18 = 1;
          goto LAB_001bf38e;
        }
      }
      (*p_Var9)();
      return;
    }
    p_Var9 = (in_EAX->super_ICDAudio)._vptr_ICDAudio[3];
    pcVar4 = Cmd_Argv(2);
    if (p_Var9 == PlayFile) {
      *(undefined4 *)&in_EAX->m_dFadeOutTime = 0;
      *(undefined4 *)((int)&in_EAX->m_dFadeOutTime + 4) = 0;
      strncpy(in_EAX->m_szPendingPlayFilename,pcVar4,0x200);
      p_Var9 = thread->_vptr_IThread[4];
      uVar18 = 0;
LAB_001bf38e:
      (*p_Var9)(thread,_Play,0,0,uVar18);
      usleep(0);
      return;
    }
  }
  (*p_Var9)();
  return;
}


// CCDAudio::CD_f  @ 001bf660
/* DWARF original prototype: void CD_f(CCDAudio * this) */

void __thiscall CCDAudio::CD_f(CCDAudio *this)

{
  int iVar1;
  
                    /* Unresolved local var: char * command@[???]
                       Unresolved local var: int ret@[???]
                       Unresolved local var: int n@[???] */
  iVar1 = Cmd_Argc();
  if (1 < iVar1) {
    CD_f(this);
    return;
  }
  return;
}


