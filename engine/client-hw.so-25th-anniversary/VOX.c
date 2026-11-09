// VOX_FPaintPitchChannelFrom8Offs  @ 001ad600
int VOX_FPaintPitchChannelFrom8Offs
              (portable_samplepair_t *paintbuffer,channel_t *ch,sfxcache_t *sc,int count,int pitch,
              int timecompress,int offset)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  portable_samplepair_t *ppVar6;
  int iVar7;
  uint uVar8;
  portable_samplepair_t *ppVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_4c;
  int local_3c;
  int local_2c;
  
                    /* Unresolved local var: int data@[???]
                       Unresolved local var: int * lscale@[???]
                       Unresolved local var: int * rscale@[???]
                       Unresolved local var: uchar * sfx@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int posold@[???]
                       Unresolved local var: int samplefrac@[???]
                       Unresolved local var: int fracstep@[???]
                       Unresolved local var: int srcsample@[???]
                       Unresolved local var: float stepscale@[???]
                       Unresolved local var: int cb@[???]
                       Unresolved local var: portable_samplepair_t * pbuffer@[???] */
  ppVar6 = paintbuffer + offset;
  iVar7 = ch->isentence;
  if (iVar7 < 0) {
    return 0;
  }
  if (ch->leftvol < 0x100) {
    iVar5 = ch->rightvol;
    iVar10 = ch->leftvol >> 3;
  }
  else {
    ch->leftvol = 0xff;
    iVar5 = ch->rightvol;
    iVar10 = 0x1f;
  }
  if (iVar5 < 0x100) {
    iVar5 = iVar5 >> 3;
  }
  else {
    ch->rightvol = 0xff;
    iVar5 = 0x1f;
  }
  iVar11 = ch->iword;
  iVar13 = (int)(((float)pitch / 100.0) * 256.0);
  iVar15 = rgrgvoxword[iVar7][iVar11].samplefrac;
  iVar2 = rgrgvoxword[iVar7][iVar11].cbtrim;
  iVar14 = iVar15 >> 8;
  iVar15 = iVar15 + iVar13;
  if (timecompress == 0) {
    if ((count < 1) || (iVar2 <= iVar14)) {
      local_4c = 0;
    }
    else {
      local_4c = 0;
      do {
        bVar1 = sc->data[iVar14];
        local_4c = local_4c + 1;
        ppVar6->left = ppVar6->left + snd_scaletable[iVar10][bVar1];
        ppVar6->right = ppVar6->right + snd_scaletable[iVar5][bVar1];
        iVar14 = iVar15 >> 8;
        ppVar6 = ppVar6 + 1;
        iVar15 = iVar15 + iVar13;
        if (count <= local_4c) break;
      } while (iVar14 < iVar2);
      iVar11 = ch->iword;
      iVar7 = ch->isentence;
    }
  }
  else {
                    /* Unresolved local var: int chunksize@[???]
                       Unresolved local var: int skipbytes@[???]
                       Unresolved local var: int lowsample@[???]
                       Unresolved local var: int playcount@[???]
                       Unresolved local var: int cdata@[???]
                       Unresolved local var: int j@[???] */
    iVar7 = iVar2 + 7;
    if (-1 < iVar2) {
      iVar7 = iVar2;
    }
    iVar7 = iVar7 >> 3;
    iVar11 = (iVar7 * timecompress) / 100;
    local_4c = 0;
    iVar12 = local_4c;
LAB_001ad7e0:
    local_4c = iVar12;
    bVar4 = local_4c < count && iVar14 < iVar2;
    if (local_4c < count && iVar14 < iVar2) {
      if (iVar14 < iVar11 || iVar11 <= iVar14 % iVar7) {
        local_2c = iVar7 - iVar14 % iVar7;
        bVar3 = true;
      }
      else {
        uVar8 = (uint)sc->data[iVar14];
        iVar12 = local_4c;
        if (4 < uVar8 + 2) {
          ppVar9 = ppVar6 + local_4c;
          do {
            iVar12 = iVar12 + 1;
            ppVar9->left = ppVar9->left + snd_scaletable[iVar10][uVar8];
            iVar14 = iVar15 >> 8;
            ppVar9->right = ppVar9->right + snd_scaletable[iVar5][uVar8];
            iVar15 = iVar15 + iVar13;
            if ((iVar12 - local_4c == 0xff || count <= iVar12) || (iVar2 <= iVar14)) break;
            ppVar9 = ppVar9 + 1;
            uVar8 = (uint)sc->data[iVar14];
          } while (4 < uVar8 + 2);
        }
        local_4c = iVar12;
        if (0x200 < local_4c) {
          Con_DPrintf("timecompress scan forward: overwrote paintbuffer!");
        }
        if (count <= local_4c || iVar2 <= iVar14) goto LAB_001ada6c;
LAB_001ad8e0:
        do {
          if (iVar14 % iVar7 < iVar11) {
            iVar12 = iVar11 - iVar14 % iVar7;
            iVar14 = iVar14 + iVar12;
            iVar15 = iVar15 + iVar12 * 0x100;
          }
          bVar3 = false;
          if (iVar2 <= iVar14) goto LAB_001ad953;
          if (2 < sc->data[iVar14]) {
            iVar12 = 0;
            do {
              iVar12 = iVar12 + 1;
              iVar14 = iVar15 >> 8;
              iVar15 = iVar15 + iVar13;
              if ((iVar2 <= iVar14) || (0xfe < iVar12)) {
                if (iVar2 <= iVar14) goto LAB_001ad953;
                iVar12 = iVar14 % iVar7;
                if (iVar11 <= iVar12) goto LAB_001ad942;
                goto LAB_001ad8e0;
              }
            } while (2 < sc->data[iVar14]);
          }
          iVar12 = iVar14 % iVar7;
        } while (iVar12 < iVar11);
LAB_001ad942:
        local_2c = iVar7 - iVar12;
        bVar3 = iVar14 < iVar2;
      }
LAB_001ad953:
      local_3c = (local_2c << 8) / iVar13;
      if (count < local_4c + local_3c) {
        local_3c = count - local_4c;
      }
      if (local_3c == 0) {
        local_3c = 1;
      }
      else {
        bVar4 = 0 < local_3c;
      }
      iVar12 = local_4c;
      if ((bVar3) && (bVar4)) {
        ppVar9 = ppVar6 + local_4c;
        do {
          bVar1 = sc->data[iVar14];
          iVar12 = iVar12 + 1;
          ppVar9->left = ppVar9->left + snd_scaletable[iVar10][bVar1];
          ppVar9->right = ppVar9->right + snd_scaletable[iVar5][bVar1];
          ppVar9 = ppVar9 + 1;
          iVar14 = iVar15 >> 8;
          iVar15 = iVar15 + iVar13;
          if (local_3c <= iVar12 - local_4c || count <= iVar12) break;
        } while (iVar14 < iVar2);
      }
      goto LAB_001ad7e0;
    }
LAB_001ada6c:
    iVar7 = ch->isentence;
    iVar11 = ch->iword;
  }
  *(int *)(iVar7 * 0x480 + 0x13cd0f8 + iVar11 * 0x24) = iVar15 - iVar13;
  iVar7 = ch->pos;
  ch->pos = iVar15 >> 8;
  ch->end = ch->end + (local_4c - ((iVar15 >> 8) - iVar7));
  return (uint)(iVar2 <= iVar14);
}


// VOX_GetDirectory  @ 001ac7b0
char * VOX_GetDirectory(char *szpath,char *psz,int nsize)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int cb@[???]
                       Unresolved local var: char * pszscan@[???] */
  iVar4 = 0;
  iVar1 = Q_strlen(psz);
  pcVar3 = psz + iVar1 + -1;
  cVar2 = *pcVar3;
  if ((cVar2 != '/') && (psz < pcVar3)) {
    do {
      pcVar3 = pcVar3 + -1;
      iVar4 = iVar4 + 1;
      cVar2 = *pcVar3;
      if (pcVar3 <= psz) break;
    } while (cVar2 != '/');
  }
  if (cVar2 == '/') {
    iVar1 = Q_strlen(psz);
    iVar1 = iVar1 - iVar4;
    if (iVar1 < nsize) {
      Q_memcpy(szpath,psz,iVar1);
      szpath[iVar1] = '\0';
      return pcVar3 + 1;
    }
    Con_DPrintf("VOX_GetDirectory: invalid directory in: %s\n",psz);
    psz = (char *)0x0;
  }
  else {
    Q_strcpy(szpath,"vox/");
  }
  return psz;
}


// VOX_IFindEmptySentence  @ 001acbe0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VOX_IFindEmptySentence(void)

{
                    /* Unresolved local var: int k@[???] */
  if (rgrgvoxword[0][0].sfx == (sfx_t *)0x0) {
    return 0;
  }
  if (rgrgvoxword[1][0].sfx == (sfx_t *)0x0) {
    return 1;
  }
  if (rgrgvoxword[2][0].sfx == (sfx_t *)0x0) {
    return 2;
  }
  if (rgrgvoxword[3][0].sfx == (sfx_t *)0x0) {
    return 3;
  }
  if (rgrgvoxword[4][0].sfx == (sfx_t *)0x0) {
    return 4;
  }
  if (rgrgvoxword[5][0].sfx == (sfx_t *)0x0) {
    return 5;
  }
  if (rgrgvoxword[6][0].sfx == (sfx_t *)0x0) {
    return 6;
  }
  if (rgrgvoxword[7][0].sfx == (sfx_t *)0x0) {
    return 7;
  }
  if (rgrgvoxword[8][0].sfx == (sfx_t *)0x0) {
    return 8;
  }
  if (rgrgvoxword[9][0].sfx == (sfx_t *)0x0) {
    return 9;
  }
  if (rgrgvoxword[10][0].sfx == (sfx_t *)0x0) {
    return 10;
  }
  if (rgrgvoxword[0xb][0].sfx == (sfx_t *)0x0) {
    return 0xb;
  }
  if (rgrgvoxword[0xc][0].sfx == (sfx_t *)0x0) {
    return 0xc;
  }
  if (rgrgvoxword[0xd][0].sfx == (sfx_t *)0x0) {
    return 0xd;
  }
  if (rgrgvoxword[0xe][0].sfx == (sfx_t *)0x0) {
    return 0xe;
  }
  if (rgrgvoxword[0xf][0].sfx != (sfx_t *)0x0) {
    Con_DPrintf("Sentence or Pitch shift ignored. > 16 playing!\n");
    return -1;
  }
  return 0xf;
}


// VOX_Init  @ 001add20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VOX_Init(void)

{
  Q_memset(rgrgvoxword,0,0x4800);
  VOX_ReadSentenceFile();
  return;
}


// VOX_LoadSound  @ 001ad030
sfxcache_t * VOX_LoadSound(channel_t *pchan,char *pszin)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  sfx_t *psVar6;
  sfxcache_t *psVar7;
  sentenceEntry_s *psVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  int in_GS_OFFSET;
  char *local_71c;
  int local_714;
  voxword_t local_700;
  int aiStack_6bc [271];
  char local_280 [32];
  char local_260 [63];
  undefined1 local_221;
  char local_220 [511];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[512] buffer@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int cword@[???]
                       Unresolved local var: char[64] pathbuffer@[???]
                       Unresolved local var: char[32] szpath@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: voxword_t[32] rgvoxword@[???]
                       Unresolved local var: char * psz@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (pszin == (char *)0x0) {
    psVar7 = (sfxcache_t *)0x0;
    goto LAB_001ad2d5;
  }
  Q_memset(&local_700,0,0x480);
  Q_memset(local_220,0,0x200);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * cptr@[???]
                       Unresolved local var: sentenceEntry_s * sentenceEntry@[???] */
  if (*pszin == '#') {
                    /* Unresolved local var: char * indexAsString@[???] */
    uVar4 = strtol(pszin + 1,(char **)0x0,10);
    psVar8 = SequenceGetSentenceByIndex(uVar4);
    if (psVar8 == (sentenceEntry_s *)0x0) goto LAB_001ad0a5;
    pcVar9 = psVar8->data;
LAB_001ad10e:
    if (pcVar9 != (char *)0x0) {
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int cb@[???]
                       Unresolved local var: char * pszscan@[???] */
      iVar3 = Q_strlen(pcVar9);
      iVar10 = 0;
      pcVar11 = pcVar9 + iVar3 + -1;
      cVar2 = *pcVar11;
      while ((pcVar9 < pcVar11 && (cVar2 != '/'))) {
        pcVar11 = pcVar11 + -1;
        iVar10 = iVar10 + 1;
        cVar2 = *pcVar11;
      }
      if (cVar2 == '/') {
        iVar3 = Q_strlen(pcVar9);
        iVar3 = iVar3 - iVar10;
        if (iVar3 < 0x20) {
          Q_memcpy(local_280,pcVar9,iVar3);
          pcVar9 = pcVar11 + 1;
          local_280[iVar3] = '\0';
          if (pcVar9 != (char *)0x0) goto LAB_001ad162;
        }
        else {
          Con_DPrintf("VOX_GetDirectory: invalid directory in: %s\n",pcVar9);
        }
        Con_DPrintf("VOX_LoadSound: failed getting directory for %s\n",pszin);
        psVar7 = (sfxcache_t *)0x0;
      }
      else {
        Q_strcpy(local_280,"vox/");
LAB_001ad162:
        local_71c = local_280;
        uVar4 = Q_strlen(pcVar9);
        if (uVar4 < 0x200) {
          iVar10 = 0;
          iVar3 = 0;
          Q_strncpy(local_220,pcVar9,0x1ff);
          local_21 = 0;
          VOX_ParseString(local_220);
LAB_001ad1ad:
          pcVar9 = rgpparseword[iVar3];
          if (pcVar9 != (char *)0x0) {
            do {
              iVar5 = VOX_ParseWordParams(pcVar9,&local_700 + iVar10,(uint)(iVar3 == 0));
              if (iVar5 != 0) {
                __snprintf_chk(local_260,0x40,1,0x40,"%s%s.wav",local_71c,rgpparseword[iVar3]);
                local_221 = 0;
                iVar5 = Q_strlen(local_260);
                if (0x3f < iVar5) goto LAB_001ad1ad;
                psVar6 = S_FindName(local_260,&(&local_700)[iVar10].fKeepCached);
                (&local_700)[iVar10].sfx = psVar6;
                iVar10 = iVar10 + 1;
              }
              iVar3 = iVar3 + 1;
              pcVar9 = rgpparseword[iVar3];
              if (pcVar9 == (char *)0x0) break;
            } while( true );
          }
                    /* Unresolved local var: int k@[???] */
          if (rgrgvoxword[0][0].sfx == (sfx_t *)0x0) {
            local_714 = 0;
          }
          else if (rgrgvoxword[1][0].sfx == (sfx_t *)0x0) {
            local_714 = 1;
          }
          else if (rgrgvoxword[2][0].sfx == (sfx_t *)0x0) {
            local_714 = 2;
          }
          else if (rgrgvoxword[3][0].sfx == (sfx_t *)0x0) {
            local_714 = 3;
          }
          else if (rgrgvoxword[4][0].sfx == (sfx_t *)0x0) {
            local_714 = 4;
          }
          else if (rgrgvoxword[5][0].sfx == (sfx_t *)0x0) {
            local_714 = 5;
          }
          else if (rgrgvoxword[6][0].sfx == (sfx_t *)0x0) {
            local_714 = 6;
          }
          else if (rgrgvoxword[7][0].sfx == (sfx_t *)0x0) {
            local_714 = 7;
          }
          else if (rgrgvoxword[8][0].sfx == (sfx_t *)0x0) {
            local_714 = 8;
          }
          else if (rgrgvoxword[9][0].sfx == (sfx_t *)0x0) {
            local_714 = 9;
          }
          else if (rgrgvoxword[10][0].sfx == (sfx_t *)0x0) {
            local_714 = 10;
          }
          else if (rgrgvoxword[0xb][0].sfx == (sfx_t *)0x0) {
            local_714 = 0xb;
          }
          else if (rgrgvoxword[0xc][0].sfx == (sfx_t *)0x0) {
            local_714 = 0xc;
          }
          else if (rgrgvoxword[0xd][0].sfx == (sfx_t *)0x0) {
            local_714 = 0xd;
          }
          else if (rgrgvoxword[0xe][0].sfx == (sfx_t *)0x0) {
            local_714 = 0xe;
          }
          else {
            if (rgrgvoxword[0xf][0].sfx != (sfx_t *)0x0) {
              Con_DPrintf("Sentence or Pitch shift ignored. > 16 playing!\n");
              psVar7 = (sfxcache_t *)0x0;
              goto LAB_001ad2d5;
            }
            local_714 = 0xf;
          }
          iVar10 = 0;
          if (local_700.sfx != (sfx_t *)0x0) {
            iVar10 = 0;
            iVar3 = 0;
            do {
              uVar4 = 0;
              do {
                *(undefined4 *)((int)&rgrgvoxword[local_714][0].volume + uVar4 + iVar3) =
                     *(undefined4 *)((int)&local_700.volume + uVar4 + iVar3);
                uVar4 = uVar4 + 4;
              } while (uVar4 < 0x24);
              iVar10 = iVar10 + 1;
              piVar1 = (int *)((int)aiStack_6bc + iVar3);
              iVar3 = iVar3 + 0x24;
            } while (*piVar1 != 0);
          }
          *(undefined4 *)(local_714 * 0x480 + 0x13cd100 + iVar10 * 0x24) = 0;
          pchan->isentence = local_714;
          pchan->iword = 0;
          pchan->sfx = rgrgvoxword[local_714][0].sfx;
          psVar7 = S_LoadSound(local_700.sfx,(channel_t *)0x0);
          if (psVar7 == (sfxcache_t *)0x0) {
            S_FreeChannel(pchan);
          }
        }
        else {
          Con_DPrintf("VOX_LoadSound: sentence is too long %s\n",pcVar9);
          psVar7 = (sfxcache_t *)0x0;
        }
      }
      goto LAB_001ad2d5;
    }
  }
  else {
LAB_001ad0a5:
    iVar10 = 0;
    if (0 < cszrawsentences) {
      do {
        iVar3 = Q_strcasecmp(pszin,rgpszrawsentence[iVar10]);
        if (iVar3 == 0) {
          pcVar9 = rgpszrawsentence[iVar10];
          iVar10 = Q_strlen(pcVar9);
          pcVar9 = pcVar9 + iVar10 + 1;
          if ((*pcVar9 == '\t') || (*pcVar9 == ' ')) {
            do {
              do {
                pcVar9 = pcVar9 + 1;
              } while (*pcVar9 == ' ');
            } while (*pcVar9 == '\t');
          }
          goto LAB_001ad10e;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < cszrawsentences);
    }
  }
  Con_DPrintf("VOX_LoadSound: no sentence named %s\n",pszin);
  psVar7 = (sfxcache_t *)0x0;
LAB_001ad2d5:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// VOX_LookupString  @ 001add90
char * VOX_LookupString(char *pszin,int *psentencenum)

{
  int iVar1;
  char *pcVar2;
  uint index;
  sentenceEntry_s *psVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * cptr@[???]
                       Unresolved local var: sentenceEntry_s * sentenceEntry@[???] */
  if (*pszin == '#') {
                    /* Unresolved local var: char * indexAsString@[???] */
    index = strtol(pszin + 1,(char **)0x0,10);
    psVar3 = SequenceGetSentenceByIndex(index);
    if (psVar3 != (sentenceEntry_s *)0x0) {
      return psVar3->data;
    }
  }
  iVar4 = 0;
  if (0 < cszrawsentences) {
    do {
      iVar1 = Q_strcasecmp(pszin,rgpszrawsentence[iVar4]);
      if (iVar1 == 0) {
        if (psentencenum != (int *)0x0) {
          *psentencenum = iVar4;
        }
        pcVar2 = rgpszrawsentence[iVar4];
        iVar4 = Q_strlen(pcVar2);
        pcVar2 = pcVar2 + iVar4 + 1;
        if ((*pcVar2 == '\t') || (*pcVar2 == ' ')) {
          do {
            do {
              pcVar2 = pcVar2 + 1;
            } while (*pcVar2 == ' ');
          } while (*pcVar2 == '\t');
        }
        return pcVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < cszrawsentences);
  }
  return (char *)0x0;
}


// VOX_MakeSingleWordSentence  @ 001acdc0
void VOX_MakeSingleWordSentence(channel_t *ch,int pitch)

{
  sfx_t *psVar1;
  int iVar2;
  
                    /* Unresolved local var: voxword_t voxword@[???]
                       Unresolved local var: int k@[???] */
                    /* Unresolved local var: int k@[???] */
  if (rgrgvoxword[0][0].sfx == (sfx_t *)0x0) {
    iVar2 = 0;
  }
  else if (rgrgvoxword[1][0].sfx == (sfx_t *)0x0) {
    iVar2 = 1;
  }
  else if (rgrgvoxword[2][0].sfx == (sfx_t *)0x0) {
    iVar2 = 2;
  }
  else if (rgrgvoxword[3][0].sfx == (sfx_t *)0x0) {
    iVar2 = 3;
  }
  else if (rgrgvoxword[4][0].sfx == (sfx_t *)0x0) {
    iVar2 = 4;
  }
  else if (rgrgvoxword[5][0].sfx == (sfx_t *)0x0) {
    iVar2 = 5;
  }
  else if (rgrgvoxword[6][0].sfx == (sfx_t *)0x0) {
    iVar2 = 6;
  }
  else if (rgrgvoxword[7][0].sfx == (sfx_t *)0x0) {
    iVar2 = 7;
  }
  else if (rgrgvoxword[8][0].sfx == (sfx_t *)0x0) {
    iVar2 = 8;
  }
  else if (rgrgvoxword[9][0].sfx == (sfx_t *)0x0) {
    iVar2 = 9;
  }
  else if (rgrgvoxword[10][0].sfx == (sfx_t *)0x0) {
    iVar2 = 10;
  }
  else if (rgrgvoxword[0xb][0].sfx == (sfx_t *)0x0) {
    iVar2 = 0xb;
  }
  else if (rgrgvoxword[0xc][0].sfx == (sfx_t *)0x0) {
    iVar2 = 0xc;
  }
  else if (rgrgvoxword[0xd][0].sfx == (sfx_t *)0x0) {
    iVar2 = 0xd;
  }
  else if (rgrgvoxword[0xe][0].sfx == (sfx_t *)0x0) {
    iVar2 = 0xe;
  }
  else {
    if (rgrgvoxword[0xf][0].sfx != (sfx_t *)0x0) {
      Con_DPrintf("Sentence or Pitch shift ignored. > 16 playing!\n");
      ch->pitch = 100;
      ch->isentence = -1;
      return;
    }
    iVar2 = 0xf;
  }
  psVar1 = ch->sfx;
  rgrgvoxword[iVar2][0].volume = 100;
  rgrgvoxword[iVar2][0].pitch = 100;
  rgrgvoxword[iVar2][0].start = 0;
  rgrgvoxword[iVar2][0].end = 100;
  rgrgvoxword[iVar2][0].fKeepCached = 1;
  rgrgvoxword[iVar2][0].samplefrac = 0;
  rgrgvoxword[iVar2][0].timecompress = 0;
  rgrgvoxword[iVar2][0].sfx = psVar1;
  rgrgvoxword[iVar2][1].sfx = (sfx_t *)0x0;
  ch->isentence = iVar2;
  ch->pitch = pitch;
  ch->iword = 0;
  return;
}


// VOX_ParseString  @ 001ac650
/* WARNING: Type propagation algorithm not settling */

void VOX_ParseString(char *psz)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fdone@[???]
                       Unresolved local var: char * pszscan@[???]
                       Unresolved local var: char c@[???] */
  Q_memset(rgpparseword,0,0x80);
  if (psz == (char *)0x0) {
    return;
  }
  rgpparseword[0] = psz;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fdone@[???]
                       Unresolved local var: char * pszscan@[???]
                       Unresolved local var: char c@[???] */
  bVar1 = 0;
  iVar5 = 1;
LAB_001ac68b:
  do {
    if (!(bool)(bVar1 ^ 1)) {
      return;
    }
    if (0x1f < iVar5) {
      return;
    }
    bVar1 = *psz;
    while( true ) {
      pbVar3 = (byte *)psz;
      if (((bVar1 & 0xdf) == 0) || ((bVar1 & 0xfd) == 0x2c)) goto joined_r0x001ac6f9;
      if (bVar1 == 0x28) break;
      psz = psz + 1;
      bVar1 = *psz;
    }
    pbVar3 = (byte *)(psz + 1);
    bVar1 = psz[1];
    while ((bVar1 != 0 && (bVar1 != 0x29))) {
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
    }
    if (bVar1 == 0) {
      return;
    }
    bVar1 = pbVar3[1];
    pbVar3 = pbVar3 + 1;
joined_r0x001ac6f9:
    if (bVar1 == 0) {
      return;
    }
    bVar2 = pbVar3[1];
    if (((bVar1 & 0xfd) == 0x2c) && ((0xd < bVar2 || (((byte)(0x2401 >> (bVar2 & 0x1f)) & 1) != 1)))
       ) {
      pcVar4 = voxperiod;
      if (bVar1 != 0x2e) {
        pcVar4 = voxcomma;
      }
      rgpparseword[iVar5] = pcVar4;
      if (0x1f < iVar5 + 1) {
        return;
      }
      bVar2 = pbVar3[1];
      iVar5 = iVar5 + 1;
    }
    psz = (char *)(pbVar3 + 1);
    *pbVar3 = 0;
    if (bVar2 != 0) {
      do {
        if (((bVar2 & 0xfd) != 0x2c) && (bVar2 != 0x20)) {
          rgpparseword[iVar5] = psz;
          bVar1 = 0;
          iVar5 = iVar5 + 1;
          goto LAB_001ac68b;
        }
        psz = psz + 1;
        bVar2 = *psz;
      } while (bVar2 != 0);
      bVar1 = 1;
      goto LAB_001ac68b;
    }
    bVar1 = 1;
  } while( true );
}


// VOX_ParseWordParams  @ 001ac8d0
int VOX_ParseWordParams(char *psz,voxword_t *pvoxword,int fFirst)

{
  char cVar1;
  char cVar2;
  char cVar3;
  ushort *puVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ushort **ppuVar9;
  char *pcVar10;
  char cVar11;
  uint uVar12;
  char *pcVar13;
  int in_GS_OFFSET;
  char local_28;
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  char local_23;
  char local_22;
  int local_20;
  
                    /* Unresolved local var: char * pszsave@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: char ct@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (fFirst != 0) {
    VOX_ParseWordParams::voxwordDefault.fKeepCached = 0;
    VOX_ParseWordParams::voxwordDefault.pitch = -1;
    VOX_ParseWordParams::voxwordDefault.volume = 100;
    VOX_ParseWordParams::voxwordDefault.start = 0;
    VOX_ParseWordParams::voxwordDefault.end = 100;
    VOX_ParseWordParams::voxwordDefault.timecompress = 0;
  }
  uVar6 = 0;
  do {
    *(undefined4 *)((int)&pvoxword->volume + uVar6) =
         *(undefined4 *)((int)&VOX_ParseWordParams::voxwordDefault.volume + uVar6);
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x24);
  iVar7 = Q_strlen(psz);
  iVar8 = 1;
  if (psz[iVar7 + -1] == ')') {
                    /* Unresolved local var: char * pszsave@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: char ct@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
    cVar11 = *psz;
    pcVar10 = psz;
    while (1 < (byte)(cVar11 - 0x28U)) {
      pcVar10 = pcVar10 + 1;
      cVar11 = *pcVar10;
    }
    if (cVar11 != ')') {
      bVar5 = pcVar10[1];
      uVar6 = (uint)bVar5;
      pcVar13 = pcVar10 + 1;
      *pcVar10 = '\0';
joined_r0x001ac9b6:
      cVar11 = '\0';
      if (bVar5 == 0) {
LAB_001ac9f6:
        Q_memset(&local_28,0,8);
        cVar1 = pcVar13[1];
        ppuVar9 = __ctype_b_loc();
        puVar4 = *ppuVar9;
        if ((*(byte *)((int)puVar4 + cVar1 * 2 + 1) & 8) == 0) goto LAB_001acb39;
        cVar2 = pcVar13[2];
        uVar6 = (uint)cVar2;
        if ((*(byte *)((int)puVar4 + uVar6 * 2 + 1) & 8) == 0) {
          pcVar13 = pcVar13 + 2;
        }
        else {
          cVar3 = pcVar13[3];
          uVar6 = (uint)cVar3;
          local_27 = cVar2;
          if ((*(byte *)((int)puVar4 + uVar6 * 2 + 1) & 8) == 0) {
            pcVar13 = pcVar13 + 3;
          }
          else {
            cVar2 = pcVar13[4];
            uVar6 = (uint)cVar2;
            local_26 = cVar3;
            if ((*(byte *)((int)puVar4 + uVar6 * 2 + 1) & 8) == 0) {
              pcVar13 = pcVar13 + 4;
            }
            else {
              cVar3 = pcVar13[5];
              uVar6 = (uint)cVar3;
              local_25 = cVar2;
              if ((*(byte *)((int)puVar4 + uVar6 * 2 + 1) & 8) == 0) {
                pcVar13 = pcVar13 + 5;
              }
              else {
                cVar2 = pcVar13[6];
                uVar6 = (uint)cVar2;
                local_24 = cVar3;
                if ((*(byte *)((int)puVar4 + uVar6 * 2 + 1) & 8) == 0) {
                  pcVar13 = pcVar13 + 6;
                }
                else {
                  pcVar10 = pcVar13 + 7;
                  uVar6 = (uint)*pcVar10;
                  local_23 = cVar2;
                  if ((*(byte *)((int)puVar4 + uVar6 * 2 + 1) & 8) == 0) {
                    pcVar13 = pcVar13 + 7;
                  }
                  else {
                    uVar6 = (uint)(byte)pcVar13[8];
                    pcVar13 = pcVar13 + 8;
                    local_22 = *pcVar10;
                  }
                }
              }
            }
          }
        }
        local_28 = cVar1;
        iVar8 = Q_atoi(&local_28);
        switch(cVar11) {
        case 'e':
          pvoxword->end = iVar8;
          uVar6 = uVar6 & 0xff;
          break;
        default:
          goto switchD_001acad8_caseD_66;
        case 'p':
          pvoxword->pitch = iVar8;
          uVar6 = uVar6 & 0xff;
          break;
        case 's':
          pvoxword->start = iVar8;
          uVar6 = uVar6 & 0xff;
          break;
        case 't':
          pvoxword->timecompress = iVar8;
          uVar6 = uVar6 & 0xff;
          break;
        case 'v':
          pvoxword->volume = iVar8;
          uVar6 = uVar6 & 0xff;
        }
      }
      else {
        cVar11 = (char)uVar6;
        bVar5 = 1;
        if ((byte)(cVar11 + 0x9bU) < 0x12) {
          bVar5 = (byte)(0x2c801 >> (cVar11 + 0x9bU & 0x1f)) & 1 ^ 1;
        }
        if ((cVar11 == ')') || (bVar5 == 0)) {
          if (cVar11 != ')') goto LAB_001ac9f6;
LAB_001acb39:
          iVar8 = Q_strlen(psz);
          if (iVar8 == 0) {
            uVar6 = 0;
            do {
              uVar12 = uVar6 + 4;
              *(undefined4 *)((int)&VOX_ParseWordParams::voxwordDefault.volume + uVar6) =
                   *(undefined4 *)((int)&pvoxword->volume + uVar6);
              uVar6 = uVar12;
            } while (uVar12 < 0x24);
            iVar8 = 0;
          }
          else {
            iVar8 = 1;
          }
          goto LAB_001ac95c;
        }
        uVar6 = (uint)(byte)pcVar13[1];
        pcVar13 = pcVar13 + 1;
switchD_001acad8_caseD_66:
        uVar6 = uVar6 & 0xff;
      }
      bVar5 = (byte)uVar6;
      goto joined_r0x001ac9b6;
    }
    iVar8 = 0;
  }
LAB_001ac95c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}


// VOX_ReadSentenceFile  @ 001ada90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VOX_ReadSentenceFile(void)

{
  char **ppcVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  byte bVar4;
  byte *p;
  byte *pbVar5;
  size_t sVar6;
  size_t sVar7;
  uint size;
  int iVar8;
  byte *pbVar9;
  byte *unaff_EBP;
  byte *pbVar10;
  byte *__s;
  byte *pbVar11;
  byte *pbVar12;
  byte bVar13;
  int local_38;
  int local_20 [4];
  
                    /* Unresolved local var: char * pBuf@[???]
                       Unresolved local var: char * pch@[???]
                       Unresolved local var: char * pchlast@[???]
                       Unresolved local var: int nSentenceCount@[???]
                       Unresolved local var: int nFileLength@[???] */
  bVar13 = 0;
                    /* Unresolved local var: int nCount@[???] */
  if (0 < cszrawsentences) {
    iVar8 = 0;
    do {
      ppcVar1 = rgpszrawsentence + iVar8;
      iVar8 = iVar8 + 1;
      Mem_Free(*ppcVar1);
    } while (iVar8 < cszrawsentences);
  }
  cszrawsentences = 0;
  p = COM_LoadFileForMe(szsentences,local_20);
  if (p == (byte *)0x0) {
    Con_DPrintf("VOX_ReadSentenceFile: Couldn\'t load %s\n",szsentences);
  }
  else {
    pbVar5 = p + local_20[0];
    local_38 = 0;
    pbVar9 = p;
LAB_001adb10:
    if (local_38 < 0x800) {
LAB_001adb1e:
      if (pbVar5 <= pbVar9) goto LAB_001adc37;
                    /* Unresolved local var: char * pszSentenceName@[???]
                       Unresolved local var: char * pszSentenceValue@[???]
                       Unresolved local var: char c@[???] */
      bVar4 = *pbVar9;
      do {
        pbVar10 = pbVar9;
        if (0x17 < (byte)(bVar4 - 9)) {
          if (bVar4 == '/') {
            bVar4 = '/';
            __s = (byte *)0x0;
            goto LAB_001adb98;
          }
LAB_001adb46:
          if ((bVar4 == ' ' || pbVar5 <= pbVar9) || (bVar4 == '\t')) goto LAB_001adb7f;
          goto LAB_001adb6c;
        }
        if (((byte)(0x800013 >> (bVar4 - 9 & 0x1f)) & 1) != 1) goto LAB_001adb46;
        pbVar9 = pbVar9 + 1;
        bVar4 = *pbVar9;
      } while (pbVar5 != pbVar9);
      pbVar10 = pbVar5;
      pbVar9 = pbVar5;
      pbVar12 = pbVar5;
      __s = pbVar5;
      if (bVar4 != '/') goto LAB_001adbe0;
      goto LAB_001adb10;
    }
LAB_001adc37:
    cszrawsentences = local_38;
    Mem_Free(p);
  }
  return;
  while (pbVar10 < pbVar5) {
LAB_001adb6c:
    pbVar10 = pbVar10 + 1;
    if (*pbVar10 == ' ' || *pbVar10 == '\t') break;
  }
LAB_001adb7f:
  pbVar12 = pbVar10;
  __s = pbVar9;
  if (pbVar10 < pbVar5) {
    unaff_EBP = pbVar10 + 1;
    bVar4 = pbVar10[1];
    *pbVar10 = '\0';
    pbVar10 = unaff_EBP;
LAB_001adb98:
    if ((pbVar10 < pbVar5 && bVar4 != '\n') && (bVar4 != '\r')) {
      do {
        pbVar10 = pbVar10 + 1;
        if (*pbVar10 == '\r' || *pbVar10 == '\n') break;
      } while (pbVar10 < pbVar5);
    }
    pbVar12 = unaff_EBP;
    if (pbVar10 < pbVar5) {
      *pbVar10 = '\0';
      pbVar10 = pbVar10 + 1;
    }
  }
LAB_001adbe0:
  pbVar9 = pbVar10;
  unaff_EBP = pbVar12;
  if (__s == (byte *)0x0) goto LAB_001adb10;
                    /* Unresolved local var: int nTotalSize@[???] */
  sVar6 = strlen((char *)__s);
  sVar7 = strlen((char *)pbVar12);
  size = sVar7 + sVar6 + 2;
  pbVar10 = Mem_Malloc(size);
  rgpszrawsentence[local_38] = (char *)pbVar10;
  if (7 < size) {
    pbVar12 = pbVar10;
    if (((uint)pbVar10 & 1) != 0) {
      bVar4 = *__s;
      pbVar12 = pbVar10 + 1;
      __s = __s + 1;
      *pbVar10 = bVar4;
      size = sVar7 + sVar6 + 1;
    }
    pbVar11 = pbVar12;
    if (((uint)pbVar12 & 2) != 0) {
      uVar2 = *(undefined2 *)__s;
      pbVar11 = pbVar12 + 2;
      __s = __s + 2;
      size = size - 2;
      *(undefined2 *)pbVar12 = uVar2;
    }
    pbVar10 = pbVar11;
    if (((uint)pbVar11 & 4) != 0) {
      uVar3 = *(undefined4 *)__s;
      pbVar10 = pbVar11 + 4;
      __s = __s + 4;
      size = size - 4;
      *(undefined4 *)pbVar11 = uVar3;
    }
  }
  for (; size != 0; size = size - 1) {
    *pbVar10 = *__s;
    __s = __s + (uint)bVar13 * -2 + 1;
    pbVar10 = pbVar10 + (uint)bVar13 * -2 + 1;
  }
  local_38 = local_38 + 1;
  if (0x7ff < local_38) goto LAB_001adc37;
  goto LAB_001adb1e;
}


// VOX_SetChanVol  @ 001ac860
void VOX_SetChanVol(channel_t *ch)

{
  int iVar1;
  float fVar2;
  
                    /* Unresolved local var: vec_t scale@[???]
                       Unresolved local var: int vol@[???] */
  if (((-1 < ch->isentence) && (iVar1 = rgrgvoxword[ch->isentence][ch->iword].volume, iVar1 != 100))
     && (fVar2 = (float)iVar1 / 100.0, fVar2 != 1.0)) {
    ch->rightvol = (int)((float)ch->rightvol * fVar2);
    ch->leftvol = (int)((float)ch->leftvol * fVar2);
  }
  return;
}


// VOX_Shutdown  @ 001add50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VOX_Shutdown(void)

{
  char **ppcVar1;
  int iVar2;
  
                    /* Unresolved local var: int nCount@[???] */
  if (0 < cszrawsentences) {
    iVar2 = 0;
    do {
      ppcVar1 = rgpszrawsentence + iVar2;
      iVar2 = iVar2 + 1;
      Mem_Free(*ppcVar1);
    } while (iVar2 < cszrawsentences);
    cszrawsentences = 0;
    return;
  }
  cszrawsentences = 0;
  return;
}


// VOX_TrimStartEndTimes  @ 001ade60
void VOX_TrimStartEndTimes(channel_t *ch,sfxcache_t *sc)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar11;
  
                    /* Unresolved local var: float sstart@[???]
                       Unresolved local var: float send@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int srcsample@[???]
                       Unresolved local var: int skiplen@[???]
                       Unresolved local var: voxword_t * pvoxword@[???]
                       Unresolved local var: char * pdata@[???] */
  iVar3 = ch->isentence;
  if (-1 < iVar3) {
    iVar4 = ch->iword;
    fVar6 = (float)rgrgvoxword[iVar3][iVar4].end;
    fVar5 = (float)rgrgvoxword[iVar3][iVar4].start;
    rgrgvoxword[iVar3][iVar4].cbtrim = sc->length;
    if (fVar5 < fVar6) {
      if ((0.0 < fVar5) && (fVar5 < 100.0)) {
        iVar9 = sc->length;
        iVar12 = (int)((fVar5 / 100.0) * (float)iVar9);
        iVar14 = iVar12 + ch->pos;
        ch->pos = iVar14;
        iVar8 = iVar14;
        if (iVar14 < iVar9) {
          if ((byte)(sc->data[iVar14] + 2) < 5) {
            iVar13 = 0;
          }
          else {
            iVar13 = 0;
            iVar11 = iVar14;
            do {
              iVar10 = iVar11 + 1;
              iVar13 = iVar13 + 1;
              iVar8 = iVar14;
              if ((iVar9 <= iVar10) || (0xfe < iVar13)) goto LAB_001ae01e;
              iVar7 = iVar11 + 1;
              iVar8 = iVar10;
              iVar11 = iVar10;
            } while (4 < (byte)(sc->data[iVar7] + 2));
          }
          ch->end = ch->end - (iVar13 + iVar12);
          ch->pos = iVar8;
        }
LAB_001ae01e:
        if (rgrgvoxword[iVar3][iVar4].pitch != 100) {
          piVar1 = &rgrgvoxword[iVar3][iVar4].samplefrac;
          *piVar1 = *piVar1 + iVar8 * 0x100;
        }
      }
      if ((0.0 < fVar6) && (fVar6 < 100.0)) {
        iVar12 = (int)(((100.0 - fVar6) / 100.0) * (float)sc->length);
        iVar8 = ch->end - iVar12;
        ch->end = iVar8;
        iVar9 = sc->length - iVar12;
        if (ch->pos < iVar9) {
          iVar14 = 0;
          bVar2 = *(byte *)((int)sc + iVar9 + 0x14);
          while (4 < (byte)(bVar2 + 2)) {
            iVar14 = iVar14 + 1;
            if (iVar14 == 0xff) {
              return;
            }
            if (iVar9 + -1 <= ch->pos) {
              return;
            }
            bVar2 = sc->data[iVar9 + -1];
            iVar9 = iVar9 + -1;
          }
          ch->end = iVar8 - iVar14;
          piVar1 = (int *)(iVar3 * 0x480 + 0x13cd0f0 + iVar4 * 0x24);
          *piVar1 = *piVar1 - (iVar14 + iVar12);
        }
      }
    }
  }
  return;
}


