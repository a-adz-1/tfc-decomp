// VOX_FPaintPitchChannelFrom8Offs  @ 001fef00
int VOX_FPaintPitchChannelFrom8Offs
              (portable_samplepair_t *paintbuffer,channel_t *ch,sfxcache_t *sc,int count,int pitch,
              int timecompress,int offset)

{
  int iVar1;
  int iVar2;
  portable_samplepair_t *ppVar3;
  int iVar4;
  int iVar5;
  portable_samplepair_t *ppVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int local_4c;
  int local_48;
  int local_30;
  
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
  iVar11 = ch->isentence;
  if (iVar11 < 0) {
    return 0;
  }
  if (ch->leftvol < 0x100) {
    iVar9 = (ch->leftvol >> 3) << 10;
    iVar12 = ch->rightvol;
  }
  else {
    ch->leftvol = 0xff;
    iVar9 = 0x7c00;
    iVar12 = ch->rightvol;
  }
  if (iVar12 < 0x100) {
    iVar12 = (iVar12 >> 3) << 10;
  }
  else {
    ch->rightvol = 0xff;
    iVar12 = 0x7c00;
  }
  iVar2 = ch->iword;
  ppVar6 = paintbuffer + offset;
  iVar13 = rgrgvoxword[iVar11][iVar2].samplefrac;
  iVar4 = (int)(((float)pitch / 100.0) * 256.0);
  iVar1 = rgrgvoxword[iVar11][iVar2].cbtrim;
  iVar10 = iVar13 >> 8;
  iVar13 = iVar13 + iVar4;
  if (timecompress == 0) {
    if ((count < 1) || (iVar1 <= iVar10)) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        iVar11 = (uint)sc->data[iVar10] * 4;
        ppVar6->left = ppVar6->left + *(int *)((int)snd_scaletable[0] + iVar11 + iVar9);
        ppVar6->right = ppVar6->right + *(int *)((int)snd_scaletable[0] + iVar11 + iVar12);
        iVar10 = iVar13 >> 8;
        ppVar6 = ppVar6 + 1;
        iVar13 = iVar13 + iVar4;
        if (iVar1 <= iVar10) break;
      } while (iVar5 < count);
      iVar2 = ch->iword;
      iVar11 = ch->isentence;
    }
  }
  else {
                    /* Unresolved local var: int chunksize@[???]
                       Unresolved local var: int skipbytes@[???]
                       Unresolved local var: int lowsample@[???]
                       Unresolved local var: int playcount@[???]
                       Unresolved local var: int cdata@[???]
                       Unresolved local var: int j@[???] */
    iVar11 = iVar1 + 7;
    if (-1 < iVar1) {
      iVar11 = iVar1;
    }
    iVar11 = iVar11 >> 3;
    iVar2 = (timecompress * iVar11) / 100;
    iVar5 = 0;
LAB_001ff0e0:
    if (iVar10 < iVar1) {
      do {
        if (count <= iVar5) break;
        iVar7 = iVar10 % iVar11;
        if ((iVar7 < iVar2) && (iVar2 <= iVar10)) {
          uVar8 = (uint)sc->data[iVar10];
          if (4 < uVar8 + 2) {
            ppVar3 = ppVar6 + iVar5;
            local_4c = 0xff;
            do {
              iVar5 = iVar5 + 1;
              ppVar3->left = ppVar3->left + *(int *)((int)snd_scaletable[0] + uVar8 * 4 + iVar9);
              ppVar3->right = ppVar3->right + *(int *)((int)snd_scaletable[0] + uVar8 * 4 + iVar12);
              iVar10 = iVar13 >> 8;
              iVar13 = iVar13 + iVar4;
              if (((iVar1 <= iVar10) || (count <= iVar5)) ||
                 (local_4c = local_4c + -1, local_4c == 0)) break;
              ppVar3 = ppVar3 + 1;
              uVar8 = (uint)sc->data[iVar10];
            } while (4 < uVar8 + 2);
          }
          if (0x200 < iVar5) {
            Con_DPrintf("timecompress scan forward: overwrote paintbuffer!");
          }
          if ((iVar1 <= iVar10) || (count <= iVar5)) break;
          do {
            if (iVar10 % iVar11 < iVar2) {
              iVar7 = iVar2 - iVar10 % iVar11;
              iVar10 = iVar10 + iVar7;
              iVar13 = iVar13 + iVar7 * 0x100;
            }
            if (iVar1 <= iVar10) goto LAB_001ff238;
            if (2 < sc->data[iVar10]) {
              iVar7 = 0;
              do {
                iVar7 = iVar7 + 1;
                iVar10 = iVar13 >> 8;
                iVar13 = iVar13 + iVar4;
                if ((0xfe < iVar7) || (iVar1 <= iVar10)) break;
              } while (2 < sc->data[iVar10]);
              if (iVar1 <= iVar10) goto LAB_001ff238;
            }
            iVar7 = iVar10 % iVar11;
          } while (iVar7 < iVar2);
        }
        local_30 = iVar11 - iVar7;
LAB_001ff238:
        local_48 = (local_30 << 8) / iVar4;
        if (count < iVar5 + local_48) {
          local_48 = count - iVar5;
        }
        if (local_48 == 0) {
          local_48 = 1;
        }
        else if (local_48 < 1) goto LAB_001ff0e0;
        if (iVar1 <= iVar10) goto LAB_001ff0e0;
        ppVar3 = ppVar6 + iVar5;
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 1;
          iVar10 = (uint)sc->data[iVar10] * 4;
          ppVar3->left = ppVar3->left + *(int *)((int)snd_scaletable[0] + iVar10 + iVar9);
          ppVar3->right = ppVar3->right + *(int *)((int)snd_scaletable[0] + iVar10 + iVar12);
          iVar10 = iVar13 >> 8;
          iVar13 = iVar13 + iVar4;
          if ((local_48 <= iVar7) || (count <= iVar5)) break;
          ppVar3 = ppVar3 + 1;
        } while (iVar10 < iVar1);
        if (iVar1 <= iVar10) break;
      } while( true );
    }
    iVar2 = ch->iword;
    iVar11 = ch->isentence;
  }
  *(int *)(iVar11 * 0x480 + 0x1365218 + iVar2 * 0x24) = iVar13 - iVar4;
  iVar11 = ch->pos;
  ch->pos = iVar13 >> 8;
  ch->end = ch->end + (iVar11 - (iVar13 >> 8)) + iVar5;
  return (uint)(iVar1 <= iVar10);
}


// VOX_GetDirectory  @ 001fe2c0
char * VOX_GetDirectory(char *szpath,char *psz,int nsize)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int cb@[???]
                       Unresolved local var: char * pszscan@[???] */
  iVar3 = 0;
  iVar2 = Q_strlen(psz);
  pcVar4 = psz + iVar2 + -1;
  cVar1 = *pcVar4;
  while ((cVar1 != '/' && (psz < pcVar4))) {
    pcVar4 = pcVar4 + -1;
    iVar3 = iVar3 + 1;
    cVar1 = *pcVar4;
  }
  if (cVar1 == '/') {
    iVar2 = Q_strlen(psz);
    iVar2 = iVar2 - iVar3;
    if (iVar2 < nsize) {
      Q_memcpy(szpath,psz,iVar2);
      szpath[iVar2] = '\0';
      return pcVar4 + 1;
    }
    pcVar4 = (char *)0x0;
    Con_DPrintf("VOX_GetDirectory: invalid directory in: %s\n",psz);
  }
  else {
    Q_strcpy(szpath,"vox/");
    pcVar4 = psz;
  }
  return pcVar4;
}


// VOX_IFindEmptySentence  @ 001fe5e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VOX_IFindEmptySentence(void)

{
  int iVar1;
  
                    /* Unresolved local var: int k@[???] */
  iVar1 = 0;
  if (((((rgrgvoxword[0][0].sfx != (sfx_t *)0x0) &&
        (iVar1 = 1, rgrgvoxword[1][0].sfx != (sfx_t *)0x0)) &&
       (iVar1 = 2, rgrgvoxword[2][0].sfx != (sfx_t *)0x0)) &&
      (((iVar1 = 3, rgrgvoxword[3][0].sfx != (sfx_t *)0x0 &&
        (iVar1 = 4, rgrgvoxword[4][0].sfx != (sfx_t *)0x0)) &&
       ((iVar1 = 5, rgrgvoxword[5][0].sfx != (sfx_t *)0x0 &&
        ((iVar1 = 6, rgrgvoxword[6][0].sfx != (sfx_t *)0x0 &&
         (iVar1 = 7, rgrgvoxword[7][0].sfx != (sfx_t *)0x0)))))))) &&
     ((iVar1 = 8, rgrgvoxword[8][0].sfx != (sfx_t *)0x0 &&
      (((((iVar1 = 9, rgrgvoxword[9][0].sfx != (sfx_t *)0x0 &&
          (iVar1 = 10, rgrgvoxword[10][0].sfx != (sfx_t *)0x0)) &&
         (iVar1 = 0xb, rgrgvoxword[0xb][0].sfx != (sfx_t *)0x0)) &&
        ((iVar1 = 0xc, rgrgvoxword[0xc][0].sfx != (sfx_t *)0x0 &&
         (iVar1 = 0xd, rgrgvoxword[0xd][0].sfx != (sfx_t *)0x0)))) &&
       ((iVar1 = 0xe, rgrgvoxword[0xe][0].sfx != (sfx_t *)0x0 &&
        (iVar1 = 0xf, rgrgvoxword[0xf][0].sfx != (sfx_t *)0x0)))))))) {
    Con_DPrintf("Sentence or Pitch shift ignored. > 16 playing!\n");
    iVar1 = -1;
  }
  return iVar1;
}


// VOX_Init  @ 001ff590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VOX_Init(void)

{
  Q_memset(rgrgvoxword,0,0x4800);
  VOX_ReadSentenceFile();
  return;
}


// VOX_LoadSound  @ 001fe980
sfxcache_t * VOX_LoadSound(channel_t *pchan,char *pszin)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  sfx_t *psVar6;
  sentenceEntry_s *psVar7;
  sfxcache_t *psVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  int local_708;
  char *local_704;
  voxword_t local_6fc;
  int aiStack_6b8 [271];
  char local_27c [511];
  undefined1 local_7d;
  char local_7c [63];
  undefined1 local_3d;
  char local_3c [44];
  
                    /* Unresolved local var: char[512] buffer@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[DW_OP_breg4(ESP): +40]
                       Unresolved local var: int cword@[???]
                       Unresolved local var: char[64] pathbuffer@[???]
                       Unresolved local var: char[32] szpath@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: voxword_t[32] rgvoxword@[???]
                       Unresolved local var: char * psz@[???] */
  if (pszin == (char *)0x0) {
    return (sfxcache_t *)0x0;
  }
  Q_memset(&local_6fc,0,0x480);
  Q_memset(local_27c,0,0x200);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * cptr@[???]
                       Unresolved local var: sentenceEntry_s * sentenceEntry@[???] */
  if (*pszin == '#') {
                    /* Unresolved local var: char * indexAsString@[???] */
    uVar4 = strtol(pszin + 1,(char **)0x0,10);
    psVar7 = SequenceGetSentenceByIndex(uVar4);
    if (psVar7 != (sentenceEntry_s *)0x0) {
      pcVar11 = psVar7->data;
LAB_001fea3c:
      if (pcVar11 != (char *)0x0) {
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int cb@[???]
                       Unresolved local var: char * pszscan@[???] */
        iVar3 = Q_strlen(pcVar11);
        iVar9 = 0;
        pcVar10 = pcVar11 + iVar3 + -1;
        cVar2 = *pcVar10;
        while ((cVar2 != '/' && (pcVar11 < pcVar10))) {
          pcVar10 = pcVar10 + -1;
          iVar9 = iVar9 + 1;
          cVar2 = *pcVar10;
        }
        if (cVar2 == '/') {
          iVar3 = Q_strlen(pcVar11);
          iVar3 = iVar3 - iVar9;
          if (iVar3 < 0x20) {
            Q_memcpy(local_3c,pcVar11,iVar3);
            pcVar11 = pcVar10 + 1;
            local_3c[iVar3] = '\0';
            if (pcVar11 != (char *)0x0) goto LAB_001fea91;
          }
          else {
            Con_DPrintf("VOX_GetDirectory: invalid directory in: %s\n",pcVar11);
          }
          Con_DPrintf("VOX_LoadSound: failed getting directory for %s\n",pszin);
          return (sfxcache_t *)0x0;
        }
        Q_strcpy(local_3c,"vox/");
LAB_001fea91:
        local_704 = local_3c;
        uVar4 = Q_strlen(pcVar11);
        if (0x1ff < uVar4) {
          Con_DPrintf("VOX_LoadSound: sentence is too long %s\n",pcVar11);
          return (sfxcache_t *)0x0;
        }
        iVar9 = 0;
        iVar3 = 0;
        Q_strncpy(local_27c,pcVar11,0x1ff);
        local_7d = 0;
        VOX_ParseString(local_27c);
LAB_001feae3:
        pcVar11 = rgpparseword[iVar9];
        do {
          if (pcVar11 == (char *)0x0) {
                    /* Unresolved local var: int k@[???] */
            if (rgrgvoxword[0][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x0;
            }
            else if (rgrgvoxword[1][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x1;
            }
            else if (rgrgvoxword[2][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x2;
            }
            else if (rgrgvoxword[3][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x3;
            }
            else if (rgrgvoxword[4][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x4;
            }
            else if (rgrgvoxword[5][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x5;
            }
            else if (rgrgvoxword[6][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x6;
            }
            else if (rgrgvoxword[7][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x7;
            }
            else if (rgrgvoxword[8][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x8;
            }
            else if (rgrgvoxword[9][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0x9;
            }
            else if (rgrgvoxword[10][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0xa;
            }
            else if (rgrgvoxword[0xb][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0xb;
            }
            else if (rgrgvoxword[0xc][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0xc;
            }
            else if (rgrgvoxword[0xd][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0xd;
            }
            else if (rgrgvoxword[0xe][0].sfx == (sfx_t *)0x0) {
              local_704 = (char *)0xe;
            }
            else {
              if (rgrgvoxword[0xf][0].sfx != (sfx_t *)0x0) {
                Con_DPrintf("Sentence or Pitch shift ignored. > 16 playing!\n");
                return (sfxcache_t *)0x0;
              }
              local_704 = (char *)0xf;
            }
            local_708 = 0;
            if (local_6fc.sfx != (sfx_t *)0x0) {
              iVar9 = 0;
              do {
                uVar4 = 0;
                do {
                  *(undefined4 *)((int)&rgrgvoxword[(int)local_704][0].volume + uVar4 + iVar9) =
                       *(undefined4 *)((int)&local_6fc.volume + uVar4 + iVar9);
                  uVar4 = uVar4 + 4;
                } while (uVar4 < 0x24);
                piVar1 = (int *)((int)aiStack_6b8 + iVar9);
                local_708 = local_708 + 1;
                iVar9 = iVar9 + 0x24;
              } while (*piVar1 != 0);
            }
            *(undefined4 *)((int)local_704 * 0x480 + 0x1365220 + local_708 * 0x24) = 0;
            pchan->isentence = (int)local_704;
            pchan->iword = 0;
            pchan->sfx = rgrgvoxword[(int)local_704][0].sfx;
            psVar8 = S_LoadSound(local_6fc.sfx,(channel_t *)0x0);
            if (psVar8 == (sfxcache_t *)0x0) {
              S_FreeChannel(pchan);
              return (sfxcache_t *)0x0;
            }
            return psVar8;
          }
          iVar5 = VOX_ParseWordParams(pcVar11,&local_6fc + iVar3,(uint)(iVar9 == 0));
          if (iVar5 != 0) {
            snprintf(local_7c,0x40,"%s%s.wav",local_704,rgpparseword[iVar9]);
            local_3d = 0;
            iVar5 = Q_strlen(local_7c);
            if (0x3f < iVar5) goto LAB_001feae3;
            psVar6 = S_FindName(local_7c,&(&local_6fc)[iVar3].fKeepCached);
            (&local_6fc)[iVar3].sfx = psVar6;
            iVar3 = iVar3 + 1;
          }
          iVar9 = iVar9 + 1;
          pcVar11 = rgpparseword[iVar9];
        } while( true );
      }
      goto LAB_001feed0;
    }
  }
  iVar9 = 0;
  if (0 < cszrawsentences) {
LAB_001fe9fd:
    iVar3 = Q_strcasecmp(pszin,rgpszrawsentence[iVar9]);
    if (iVar3 != 0) goto LAB_001fe9f0;
    pcVar11 = rgpszrawsentence[iVar9];
    iVar9 = Q_strlen(pcVar11);
    pcVar11 = pcVar11 + iVar9 + 1;
    cVar2 = *pcVar11;
    if (cVar2 != '\t') goto LAB_001fea38;
    do {
      do {
        pcVar11 = pcVar11 + 1;
        cVar2 = *pcVar11;
      } while (cVar2 == '\t');
LAB_001fea38:
    } while (cVar2 == ' ');
    goto LAB_001fea3c;
  }
LAB_001feed0:
  Con_DPrintf("VOX_LoadSound: no sentence named %s\n",pszin);
  return (sfxcache_t *)0x0;
LAB_001fe9f0:
  iVar9 = iVar9 + 1;
  if (cszrawsentences <= iVar9) goto LAB_001feed0;
  goto LAB_001fe9fd;
}


// VOX_LookupString  @ 001ff600
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
        if ((*pcVar2 == ' ') || (*pcVar2 == '\t')) {
          do {
            do {
              pcVar2 = pcVar2 + 1;
            } while (*pcVar2 == '\t');
          } while (*pcVar2 == ' ');
        }
        return pcVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < cszrawsentences);
  }
  return (char *)0x0;
}


// VOX_MakeSingleWordSentence  @ 001fe710
void VOX_MakeSingleWordSentence(channel_t *ch,int pitch)

{
  sfx_t *psVar1;
  int iVar2;
  
                    /* Unresolved local var: voxword_t voxword@[???]
                       Unresolved local var: int k@[DW_OP_reg1(ECX)] */
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
  rgrgvoxword[iVar2][1].sfx = (sfx_t *)0x0;
  rgrgvoxword[iVar2][0].sfx = psVar1;
  ch->isentence = iVar2;
  ch->iword = 0;
  ch->pitch = pitch;
  return;
}


// VOX_ParseString  @ 001fe170
void VOX_ParseString(char *psz)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fdone@[???]
                       Unresolved local var: char * pszscan@[???]
                       Unresolved local var: char c@[???] */
  Q_memset(rgpparseword,0,0x80);
  if (psz == (char *)0x0) {
    return;
  }
  rgpparseword[0] = psz;
  bVar1 = false;
  iVar4 = 1;
LAB_001fe1a5:
  do {
    if (bVar1) {
      return;
    }
    if (0x1f < iVar4) {
      return;
    }
    for (; (((cVar2 = *psz, cVar2 != ' ' && (cVar2 != '\0')) && (cVar2 != ',')) && (cVar2 != '.'));
        psz = psz + 1) {
      if (cVar2 == '(') goto LAB_001fe1f8;
    }
    if (cVar2 == '(') {
LAB_001fe1f8:
      cVar2 = psz[1];
      pcVar5 = psz + 1;
      if ((cVar2 != '\0') && (cVar2 != ')')) {
        do {
          pcVar5 = pcVar5 + 1;
          cVar2 = *pcVar5;
          if (cVar2 == ')') break;
        } while (cVar2 != '\0');
      }
      if (cVar2 == '\0') {
        return;
      }
      cVar2 = pcVar5[1];
      psz = pcVar5 + 1;
    }
    if (cVar2 == '\0') {
      return;
    }
    cVar3 = psz[1];
    if (((cVar2 == ',') || (cVar2 == '.')) &&
       ((cVar3 != '\n' && ((cVar3 != '\r' && (cVar3 != '\0')))))) {
      if (cVar2 == '.') {
        rgpparseword[iVar4] = voxperiod;
      }
      else {
        rgpparseword[iVar4] = voxcomma;
      }
      iVar4 = iVar4 + 1;
      if (0x1f < iVar4) {
        return;
      }
      cVar3 = psz[1];
    }
    *psz = '\0';
    psz = psz + 1;
    while (cVar3 != '\0') {
      if (((cVar3 != '.') && (cVar3 != ' ')) && (cVar3 != ',')) {
        rgpparseword[iVar4] = psz;
        bVar1 = false;
        iVar4 = iVar4 + 1;
        goto LAB_001fe1a5;
      }
      psz = psz + 1;
      cVar3 = *psz;
    }
    bVar1 = true;
  } while( true );
}


// VOX_ParseWordParams  @ 001fe3e0
int VOX_ParseWordParams(char *psz,voxword_t *pvoxword,int fFirst)

{
  ushort *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ushort **ppuVar6;
  char *pcVar7;
  char cVar8;
  char *pcVar9;
  char local_2c [28];
  
                    /* Unresolved local var: char * pszsave@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: char ct@[???]
                       Unresolved local var: char[8] sznum@[???]
                       Unresolved local var: int i@[???] */
  if (fFirst != 0) {
    VOX_ParseWordParams::voxwordDefault.fKeepCached = 0;
    VOX_ParseWordParams::voxwordDefault.pitch = -1;
    VOX_ParseWordParams::voxwordDefault.volume = 100;
    VOX_ParseWordParams::voxwordDefault.start = 0;
    VOX_ParseWordParams::voxwordDefault.end = 100;
    VOX_ParseWordParams::voxwordDefault.timecompress = 0;
  }
  uVar3 = 0;
  do {
    *(undefined4 *)((int)&pvoxword->volume + uVar3) =
         *(undefined4 *)((int)&VOX_ParseWordParams::voxwordDefault.volume + uVar3);
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x24);
  iVar4 = Q_strlen(psz);
  iVar5 = 1;
  pcVar7 = psz;
  if (psz[iVar4 + -1] == ')') {
    for (; 1 < (byte)(*pcVar7 - 0x28U); pcVar7 = pcVar7 + 1) {
    }
    iVar5 = 0;
    if (*pcVar7 != ')') {
      pcVar9 = pcVar7 + 1;
      *pcVar7 = '\0';
      cVar2 = pcVar7[1];
      while( true ) {
        while ((((cVar2 != 'v' && (cVar2 != '\0')) && (cVar2 != 's')) &&
               (((cVar2 != 'p' && (cVar2 != 't')) && (cVar2 != 'e'))))) {
          if (cVar2 == ')') goto LAB_001fe5a0;
          pcVar7 = pcVar9 + 1;
          pcVar9 = pcVar9 + 1;
          cVar2 = *pcVar7;
        }
        if (cVar2 == ')') break;
        Q_memset(local_2c,0,8);
        cVar8 = pcVar9[1];
        ppuVar6 = __ctype_b_loc();
        puVar1 = *ppuVar6;
        if ((*(byte *)((int)puVar1 + cVar8 * 2 + 1) & 8) == 0) break;
        pcVar9 = pcVar9 + 1;
        uVar3 = 0;
        do {
          pcVar9 = pcVar9 + 1;
          local_2c[uVar3] = cVar8;
          cVar8 = *pcVar9;
          uVar3 = uVar3 + 1;
          if ((*(byte *)((int)puVar1 + cVar8 * 2 + 1) & 8) == 0) break;
        } while (uVar3 < 7);
        iVar4 = Q_atoi(local_2c);
        switch(cVar2) {
        case 'e':
          pvoxword->end = iVar4;
          cVar2 = cVar8;
          break;
        default:
          cVar2 = cVar8;
          break;
        case 'p':
          pvoxword->pitch = iVar4;
          cVar2 = cVar8;
          break;
        case 's':
          pvoxword->start = iVar4;
          cVar2 = cVar8;
          break;
        case 't':
          pvoxword->timecompress = iVar4;
          cVar2 = cVar8;
          break;
        case 'v':
          pvoxword->volume = iVar4;
          cVar2 = cVar8;
        }
      }
LAB_001fe5a0:
      iVar4 = Q_strlen(psz);
      iVar5 = 1;
      if (iVar4 == 0) {
        uVar3 = 0;
        do {
          *(undefined4 *)((int)&VOX_ParseWordParams::voxwordDefault.volume + uVar3) =
               *(undefined4 *)((int)&pvoxword->volume + uVar3);
          uVar3 = uVar3 + 4;
        } while (uVar3 < 0x24);
        iVar5 = 0;
      }
    }
  }
  return iVar5;
}


// VOX_ReadSentenceFile  @ 001ff340
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VOX_ReadSentenceFile(void)

{
  char **ppcVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  byte bVar4;
  byte *p;
  size_t sVar5;
  size_t sVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *__s;
  uint size;
  byte bVar12;
  int local_3c;
  byte *local_38;
  int local_2c [7];
  
                    /* Unresolved local var: char * pBuf@[???]
                       Unresolved local var: char * pch@[???]
                       Unresolved local var: char * pchlast@[???]
                       Unresolved local var: int nSentenceCount@[???]
                       Unresolved local var: int nFileLength@[???] */
  bVar12 = 0;
                    /* Unresolved local var: int nCount@[???] */
  if (0 < cszrawsentences) {
    iVar9 = 0;
    do {
      ppcVar1 = rgpszrawsentence + iVar9;
      iVar9 = iVar9 + 1;
      Mem_Free(*ppcVar1);
    } while (iVar9 < cszrawsentences);
  }
  cszrawsentences = 0;
  p = COM_LoadFileForMe(szsentences,local_2c);
  if (p == (byte *)0x0) {
    Con_DPrintf("VOX_ReadSentenceFile: Couldn\'t load %s\n",szsentences);
  }
  else {
    pbVar11 = p + local_2c[0];
    local_3c = 0;
    pbVar10 = p;
LAB_001ff3af:
    if (pbVar10 < pbVar11) {
      do {
        if (0x5ff < local_3c) break;
                    /* Unresolved local var: char * pszSentenceName@[???]
                       Unresolved local var: char * pszSentenceValue@[???]
                       Unresolved local var: char c@[???] */
        bVar4 = *pbVar10;
        do {
          if ((((bVar4 != '\r') && (bVar4 != '\n')) && (bVar4 != ' ')) && (bVar4 != '\t')) {
            bVar4 = *pbVar10;
            pbVar7 = pbVar10;
            break;
          }
          pbVar10 = pbVar10 + 1;
          bVar4 = *pbVar10;
          pbVar7 = pbVar10;
        } while (pbVar10 < pbVar11);
        pbVar10 = pbVar7;
        __s = (byte *)0x0;
        if (bVar4 != '/') {
          if ((bVar4 != ' ') && (pbVar7 < pbVar11)) {
            while (bVar4 != '\t') {
              pbVar10 = pbVar10 + 1;
              bVar4 = *pbVar10;
              if ((bVar4 == ' ') || (pbVar11 <= pbVar10)) break;
            }
          }
          __s = pbVar7;
          local_38 = pbVar10;
          if (pbVar10 < pbVar11) {
            *pbVar10 = '\0';
            bVar4 = pbVar10[1];
            pbVar10 = pbVar10 + 1;
            local_38 = pbVar10;
          }
        }
        if ((pbVar10 < pbVar11) && (bVar4 != '\n')) {
          while (bVar4 != '\r') {
            pbVar10 = pbVar10 + 1;
            bVar4 = *pbVar10;
            if ((bVar4 == '\n') || (pbVar11 <= pbVar10)) break;
          }
        }
        if (pbVar10 < pbVar11) {
          *pbVar10 = '\0';
          pbVar10 = pbVar10 + 1;
        }
        if (__s == (byte *)0x0) goto LAB_001ff3af;
                    /* Unresolved local var: int nTotalSize@[???] */
        sVar5 = strlen((char *)__s);
        sVar6 = strlen((char *)local_38);
        size = sVar6 + sVar5 + 2;
        pbVar7 = Mem_Malloc(size);
        rgpszrawsentence[local_3c] = (char *)pbVar7;
        if (7 < size) {
          uVar8 = size;
          if (((uint)pbVar7 & 1) != 0) {
            bVar4 = *__s;
            __s = __s + 1;
            *pbVar7 = bVar4;
            pbVar7 = pbVar7 + 1;
            uVar8 = sVar6 + sVar5 + 1;
          }
          if (((uint)pbVar7 & 2) != 0) {
            uVar2 = *(undefined2 *)__s;
            uVar8 = uVar8 - 2;
            __s = __s + 2;
            *(undefined2 *)pbVar7 = uVar2;
            pbVar7 = pbVar7 + 2;
          }
          if (((uint)pbVar7 & 4) != 0) {
            uVar3 = *(undefined4 *)__s;
            uVar8 = uVar8 - 4;
            __s = __s + 4;
            *(undefined4 *)pbVar7 = uVar3;
            pbVar7 = pbVar7 + 4;
          }
          size = uVar8 & 3;
          for (uVar8 = uVar8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pbVar7 = *(undefined4 *)__s;
            __s = __s + (uint)bVar12 * -8 + 4;
            pbVar7 = pbVar7 + (uint)bVar12 * -8 + 4;
          }
        }
        iVar9 = 0;
        if ((size & 4) != 0) {
          iVar9 = 4;
          *(undefined4 *)pbVar7 = *(undefined4 *)__s;
        }
        if ((size & 2) != 0) {
          *(undefined2 *)(pbVar7 + iVar9) = *(undefined2 *)(__s + iVar9);
          iVar9 = iVar9 + 2;
        }
        if ((size & 1) != 0) {
          pbVar7[iVar9] = __s[iVar9];
        }
        local_3c = local_3c + 1;
        if (pbVar11 <= pbVar10) break;
      } while( true );
    }
    cszrawsentences = local_3c;
    Mem_Free(p);
  }
  return;
}


// VOX_SetChanVol  @ 001fe370
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


// VOX_Shutdown  @ 001ff5c0
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
  }
  cszrawsentences = 0;
  return;
}


// VOX_TrimStartEndTimes  @ 001ff6e0
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
  int iVar11;
  int iVar12;
  int local_20;
  
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
        iVar11 = sc->length;
        iVar8 = (int)((fVar5 / 100.0) * (float)iVar11);
        local_20 = iVar8 + ch->pos;
        ch->pos = local_20;
        if (local_20 < iVar11) {
          iVar12 = 0;
          iVar9 = local_20;
          if ((byte)(sc->data[local_20] + 2) < 5) {
            iVar12 = 0;
            iVar10 = local_20;
          }
          else {
            do {
              iVar12 = iVar12 + 1;
              iVar10 = iVar9 + 1;
              if ((0xfe < iVar12) || (iVar11 <= iVar10)) goto LAB_001ff79d;
              iVar7 = iVar9 + 1;
              iVar9 = iVar10;
            } while (4 < (byte)(sc->data[iVar7] + 2));
          }
          ch->pos = iVar10;
          ch->end = ch->end - (iVar12 + iVar8);
          local_20 = iVar10;
        }
LAB_001ff79d:
        if (rgrgvoxword[iVar3][iVar4].pitch != 100) {
          piVar1 = &rgrgvoxword[iVar3][iVar4].samplefrac;
          *piVar1 = *piVar1 + local_20 * 0x100;
        }
      }
      if ((0.0 < fVar6) && (fVar6 < 100.0)) {
        iVar8 = (int)(((100.0 - fVar6) / 100.0) * (float)sc->length);
        iVar9 = ch->end - iVar8;
        ch->end = iVar9;
        iVar11 = sc->length - iVar8;
        if (ch->pos < iVar11) {
          iVar12 = 0;
          bVar2 = *(byte *)((int)sc + iVar11 + 0x14);
          while (4 < (byte)(bVar2 + 2)) {
            iVar12 = iVar12 + 1;
            if (0xfe < iVar12) {
              return;
            }
            if (iVar11 + -1 <= ch->pos) {
              return;
            }
            bVar2 = sc->data[iVar11 + -1];
            iVar11 = iVar11 + -1;
          }
          ch->end = iVar9 - iVar12;
          piVar1 = &rgrgvoxword[iVar3][iVar4].cbtrim;
          *piVar1 = *piVar1 - (iVar12 + iVar8);
        }
      }
    }
  }
  return;
}


