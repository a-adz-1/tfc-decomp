// CCDAudio::CD_f  @ 0020ecf0
/* DWARF original prototype: void CD_f(CCDAudio * this) */

void __thiscall CCDAudio::CD_f(CCDAudio *this)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  long lVar5;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int arg;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar9;
  
                    /* Unresolved local var: char * command@[???]
                       Unresolved local var: int ret@[???]
                       Unresolved local var: int n@[???] */
  iVar2 = Cmd_Argc();
  if (iVar2 < 2) {
    return;
  }
  pcVar3 = Cmd_Argv(1);
  iVar2 = strcasecmp(pcVar3,"on");
  if (iVar2 == 0) {
    this->m_bEnabled = true;
    return;
  }
  iVar2 = strcasecmp(pcVar3,"off");
  if (iVar2 == 0) {
    if (this->m_bIsPlaying != false) {
      (*thread->_vptr_IThread[4])(thread,_Stop,0,0,0);
    }
    this->m_bEnabled = false;
    return;
  }
  iVar2 = strcasecmp(pcVar3,"reset");
  if (iVar2 != 0) {
    iVar2 = strcasecmp(pcVar3,"remap");
    if (iVar2 == 0) {
      iVar2 = Cmd_Argc();
      if (iVar2 < 3) {
        return;
      }
      iVar9 = 1;
      do {
        arg = iVar9 + 1;
        pcVar3 = Cmd_Argv(arg);
        lVar5 = strtol(pcVar3,(char **)0x0,10);
        this->m_rgRemapCD[iVar9] = lVar5;
        iVar9 = arg;
      } while (arg != iVar2 + -1);
      return;
    }
    iVar2 = strcasecmp(pcVar3,"close");
    if (iVar2 == 0) {
      (*thread->_vptr_IThread[4])(thread,_CloseDoor,0,0,0);
      return;
    }
    iVar2 = strcasecmp(pcVar3,"mp3info");
    if (iVar2 == 0) {
      Con_Printf("Current MP3 Title: %s\n",(this->m_MP3).trackname);
      Con_Printf("Current MP3 Track: %i\n",(this->m_MP3).tracknum);
      Con_Printf("Current MP3 Volume: %i\n",(double)(this->m_MP3).volume);
      return;
    }
    iVar2 = Cmd_Argc();
    if ((2 < iVar2) && (iVar2 = strcasecmp(pcVar3,"mp3track"), iVar2 == 0)) {
      pcVar3 = Cmd_Argv(2);
      lVar5 = strtol(pcVar3,(char **)0x0,10);
      bVar1 = MP3_PlayTrack(this,lVar5 + 1,false);
      if (!bVar1) {
        return;
      }
      this->m_flPlayTime = 0.0;
      *(undefined4 *)&this->m_dStartTime = 0;
      *(undefined4 *)((int)&this->m_dStartTime + 4) = 0;
      *(undefined4 *)&this->m_dPauseTime = 0;
      *(undefined4 *)((int)&this->m_dPauseTime + 4) = 0;
      this->m_bIsLooping = false;
      this->m_nPlayTrack = lVar5 + 1;
      this->m_bIsPlaying = true;
      return;
    }
    iVar2 = strcasecmp(pcVar3,"play");
    if (iVar2 == 0) {
      UNRECOVERED_JUMPTABLE = (this->super_ICDAudio)._vptr_ICDAudio[2];
      pcVar3 = Cmd_Argv(2);
      lVar5 = strtol(pcVar3,(char **)0x0,10);
      (*UNRECOVERED_JUMPTABLE)(this,lVar5,0);
      return;
    }
    iVar2 = strcasecmp(pcVar3,"playfile");
    if (iVar2 == 0) {
      UNRECOVERED_JUMPTABLE = (this->super_ICDAudio)._vptr_ICDAudio[3];
      pcVar3 = Cmd_Argv(2);
      (*UNRECOVERED_JUMPTABLE)(this,pcVar3,0);
      return;
    }
    iVar2 = strcasecmp(pcVar3,"loop");
    if (iVar2 == 0) {
      UNRECOVERED_JUMPTABLE = (this->super_ICDAudio)._vptr_ICDAudio[2];
      pcVar3 = Cmd_Argv(2);
      lVar5 = strtol(pcVar3,(char **)0x0,10);
      (*UNRECOVERED_JUMPTABLE)(this,lVar5,1);
      return;
    }
    iVar2 = strcasecmp(pcVar3,"loopfile");
    if (iVar2 == 0) {
      UNRECOVERED_JUMPTABLE = (this->super_ICDAudio)._vptr_ICDAudio[3];
      pcVar3 = Cmd_Argv(2);
      (*UNRECOVERED_JUMPTABLE)(this,pcVar3,1);
      return;
    }
    iVar2 = strcasecmp(pcVar3,"stop");
    if (iVar2 == 0) {
      Stop(this);
      return;
    }
    iVar2 = strcasecmp(pcVar3,"fadeout");
    if (iVar2 == 0) {
      FadeOut(this);
      return;
    }
    iVar2 = strcasecmp(pcVar3,"pause");
    if (iVar2 == 0) {
      UNRECOVERED_JUMPTABLE = (this->super_ICDAudio)._vptr_ICDAudio[4];
    }
    else {
      iVar2 = strcasecmp(pcVar3,"resume");
      if (iVar2 != 0) {
        iVar2 = strcasecmp(pcVar3,"eject");
        if (iVar2 == 0) {
          if (this->m_bIsPlaying != false) {
            Stop(this);
          }
          Eject(this);
          this->m_bIsCDValid = false;
          return;
        }
        iVar2 = strcasecmp(pcVar3,"info");
        if (iVar2 != 0) {
          return;
        }
        Con_Printf("%u tracks\n",g_iMP3NumTracks + -1);
        if (this->m_bIsPlaying == false) {
          if (this->m_bWasPlaying != false) {
            pcVar3 = "looping";
            if (this->m_bIsLooping == false) {
              pcVar3 = "playing";
            }
            Con_Printf("Paused %s track %u\n",pcVar3,this->m_nPlayTrack);
          }
        }
        else {
          pcVar3 = "looping";
          if (this->m_bIsLooping == false) {
            pcVar3 = "playing";
          }
          Con_Printf("Currently %s track %u\n",pcVar3,this->m_nPlayTrack);
        }
        Con_Printf("Volume is %f\n",(double)this->m_flVolume);
        return;
      }
      UNRECOVERED_JUMPTABLE = (this->super_ICDAudio)._vptr_ICDAudio[5];
    }
                    /* WARNING: Could not recover jumptable at 0x0020f31e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  this->m_bEnabled = true;
  if (this->m_bIsPlaying != false) {
    (*thread->_vptr_IThread[4])(thread,_Stop,0,0,0);
  }
  uVar6 = -(((uint)this & 0xf) >> 2) & 3;
  if (uVar6 == 0) {
    iVar2 = 100;
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    do {
      this->m_rgRemapCD[uVar4] = uVar4;
      uVar4 = uVar4 + 1;
      iVar2 = 100 - uVar4;
    } while (uVar4 < uVar6);
  }
  uVar10 = 100 - uVar6 >> 2;
  if (uVar10 != 0) {
    uVar12 = uVar4 + 1;
    uVar13 = uVar4 + 2;
    uVar14 = uVar4 + 3;
    piVar8 = this->m_rgRemapCD + uVar6;
    uVar7 = 0;
    uVar11 = uVar4;
    do {
      uVar7 = uVar7 + 1;
      *piVar8 = uVar11;
      piVar8[1] = uVar12;
      piVar8[2] = uVar13;
      piVar8[3] = uVar14;
      piVar8 = piVar8 + 4;
      uVar11 = uVar11 + 4;
      uVar12 = uVar12 + 4;
      uVar13 = uVar13 + 4;
      uVar14 = uVar14 + 4;
    } while (uVar7 < uVar10);
    uVar4 = uVar4 + uVar10 * 4;
    iVar2 = iVar2 + uVar10 * -4;
    if (uVar10 * 4 == 100 - uVar6) goto LAB_0020ee4b;
  }
  do {
    this->m_rgRemapCD[uVar4] = uVar4;
    uVar4 = uVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
LAB_0020ee4b:
  (*thread->_vptr_IThread[4])(thread,_GetAudioDiskInfo,0,0,0);
  return;
}


