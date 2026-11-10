// SENTENCEG_GetIndex__FPCc  @ 000f261c
int SENTENCEG_GetIndex__FPCc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  if (((fSentencesInit != 0) && (param_1 != (char *)0x0)) && (rgsentenceg._16_4_ != 0)) {
    iVar2 = 0;
    do {
      iVar1 = strcmp(param_1,rgsentenceg + iVar2 * 0x34);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (*(int *)(rgsentenceg + iVar2 * 0x34 + 0x10) != 0);
  }
  return -1;
}


// SENTENCEG_Init__Fv  @ 000f09f4
void SENTENCEG_Init__Fv(void)

{
  undefined1 uVar1;
  uint *puVar2;
  char cVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *__src;
  char *pcVar11;
  int local_254;
  int local_250;
  undefined4 local_24c;
  undefined4 local_248;
  char local_244 [63];
  char cStack_205;
  undefined1 local_204 [512];
  
  if (fSentencesInit == 0) {
    memset(gszallsentencenames,0,0x6000);
    gcallsentences = 0;
    memset(rgsentenceg,0,0x28a0);
    memset(local_204,0,0x200);
    memset(local_244,0,0x40);
    local_254 = -1;
    local_24c = 0;
    iVar4 = (*DAT_0019f81c)("sound/sentences.txt",&local_248);
    if (iVar4 != 0) {
LAB_000f0d51:
      iVar6 = memfgets__FPUciRiPci(iVar4,local_248,&local_24c,local_204,0x1ff);
      if (iVar6 != 0) {
        local_250 = 0;
        cVar3 = local_204[0];
        while (cVar3 == ' ') {
          local_250 = local_250 + 1;
          cVar3 = local_204[local_250];
        }
        cVar3 = local_204[local_250];
        if ((((cVar3 != '\0') && (cVar3 != '/')) &&
            (iVar6 = isalpha((int)(char)local_204[local_250]), iVar6 != 0)) &&
           (iVar6 = local_250, local_204[local_250] != '\0')) {
          do {
            cVar3 = local_204[iVar6];
            if (cVar3 == ' ') break;
            iVar6 = iVar6 + 1;
            cVar3 = '\0';
          } while (local_204[iVar6] != '\0');
          if (cVar3 != '\0') {
            if (gcallsentences < 0x601) {
              local_204[iVar6] = 0;
              __src = (uint *)(local_204 + local_250);
              uVar9 = (uint)__src & 3;
              puVar2 = __src;
              if (uVar9 == 0) {
LAB_000f0bcd:
                do {
                  puVar5 = puVar2;
                  uVar9 = *puVar5;
                  if ((char)uVar9 == '\0') goto LAB_000f0bef;
                  if ((char)(uVar9 >> 8) == '\0') goto LAB_000f0bee;
                  if ((uVar9 & 0xff0000) == 0) goto LAB_000f0bed;
                  puVar2 = puVar5 + 1;
                } while ((uVar9 & 0xff000000) != 0);
                puVar5 = (uint *)((int)puVar5 + 1);
LAB_000f0bed:
                puVar5 = (uint *)((int)puVar5 + 1);
LAB_000f0bee:
                puVar5 = (uint *)((int)puVar5 + 1);
              }
              else {
                puVar5 = __src;
                if ((POPCOUNT(uVar9) & 1U) == 0) {
LAB_000f0bc8:
                  if ((char)*puVar5 != '\0') {
                    puVar2 = (uint *)((int)puVar5 + 1);
                    goto LAB_000f0bcd;
                  }
                }
                else if (uVar9 == 2) {
LAB_000f0bc3:
                  if ((char)*puVar5 != '\0') {
                    puVar5 = (uint *)((int)puVar5 + 1);
                    goto LAB_000f0bc8;
                  }
                }
                else if ((char)*__src != '\0') {
                  puVar5 = (uint *)(local_204 + local_250 + 1);
                  goto LAB_000f0bc3;
                }
              }
LAB_000f0bef:
              if (0xf < (uint)((int)puVar5 - (int)__src)) {
                (*DAT_0019f794)(3,"Sentence %s longer than %d letters\n",__src,0xf);
              }
              iVar10 = gcallsentences * 0x10;
              gcallsentences = gcallsentences + 1;
              strcpy(gszallsentencenames + iVar10,(char *)__src);
              iVar6 = iVar6 + -1;
              if ((iVar6 <= local_250) ||
                 (iVar10 = isdigit((int)(char)local_204[iVar6]), iVar10 == 0)) goto LAB_000f0d51;
              do {
                iVar10 = isdigit((int)(char)local_204[iVar6]);
                if (iVar10 == 0) break;
                iVar6 = iVar6 + -1;
              } while (local_250 < iVar6);
              if (iVar6 <= local_250) goto LAB_000f0d51;
              local_204[iVar6 + 1] = 0;
              pcVar11 = local_204 + local_250;
              iVar6 = strcmp(local_244,pcVar11);
              if (iVar6 == 0) {
                if (-1 < local_254) {
                  *(int *)(rgsentenceg + local_254 * 0x34 + 0x10) =
                       *(int *)(rgsentenceg + local_254 * 0x34 + 0x10) + 1;
                }
                goto LAB_000f0d51;
              }
              local_254 = local_254 + 1;
              if (local_254 < 200) {
                strcpy(rgsentenceg + local_254 * 0x34,pcVar11);
                *(undefined4 *)(rgsentenceg + local_254 * 0x34 + 0x10) = 1;
                strcpy(local_244,pcVar11);
                goto LAB_000f0d51;
              }
              pcVar11 = "Too many sentence groups in sentences.txt!\n";
            }
            else {
              pcVar11 = "Too many sentences in sentences.txt!\n";
            }
            (*DAT_0019f794)(4,pcVar11);
            goto LAB_000f0d82;
          }
        }
        goto LAB_000f0d51;
      }
LAB_000f0d82:
      (*DAT_0019f820)(iVar4);
      fSentencesInit = 1;
      local_250 = 0;
      iVar4 = rgsentenceg._16_4_;
      while ((iVar4 != 0 && (local_250 < 200))) {
        iVar4 = local_250 * 0x34 + 0x1a7d74;
        iVar6 = *(int *)(rgsentenceg + local_250 * 0x34 + 0x10);
        if (fSentencesInit != 0) {
          if (0x20 < iVar6) {
            iVar6 = 0x20;
          }
          iVar10 = 0;
          if (0 < iVar6) {
            do {
              *(char *)(iVar10 + iVar4) = (char)iVar10;
              iVar10 = iVar10 + 1;
            } while (iVar10 < iVar6);
          }
          if (0 < iVar6 * 4) {
            iVar10 = 0;
            do {
              iVar7 = (*DAT_0019f808)(0,iVar6 + -1);
              iVar8 = (*DAT_0019f808)(0,iVar6 + -1);
              uVar1 = *(undefined1 *)(iVar7 + iVar4);
              *(undefined1 *)(iVar7 + iVar4) = *(undefined1 *)(iVar8 + iVar4);
              iVar10 = iVar10 + 1;
              *(undefined1 *)(iVar8 + iVar4) = uVar1;
            } while (iVar10 < iVar6 * 4);
          }
        }
        local_250 = local_250 + 1;
        iVar4 = *(int *)(rgsentenceg + local_250 * 0x34 + 0x10);
      }
    }
  }
  return;
}


// SENTENCEG_Lookup__FPCcPc  @ 000f2398
int SENTENCEG_Lookup__FPCcPc(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char local_c [8];
  
  iVar2 = 0;
  if (0 < gcallsentences) {
    do {
      iVar1 = strcasecmp(gszallsentencenames + iVar2 * 0x10,(char *)(param_1 + 1));
      if (iVar1 == 0) {
        if (param_2 == (char *)0x0) {
          return iVar2;
        }
        param_2[0] = '!';
        param_2[1] = '\0';
        sprintf(local_c,"%d",iVar2);
        strcat(param_2,local_c);
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < gcallsentences);
  }
  return -1;
}


// SENTENCEG_PlayRndI__FP7edict_siffii  @ 000f25a8
int SENTENCEG_PlayRndI__FP7edict_siffii
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined1 local_44 [64];
  
  if (fSentencesInit == 0) {
    iVar1 = -1;
  }
  else {
    local_44[0] = 0;
    iVar1 = USENTENCEG_Pick__FiPc(param_2,local_44);
    if (0 < iVar1) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,param_3,param_4,param_5,param_6);
    }
  }
  return iVar1;
}


// SENTENCEG_PlayRndSz__FP7edict_sPCcffii  @ 000f24b0
int SENTENCEG_PlayRndSz__FP7edict_sPCcffii
              (undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  char local_44 [64];
  
  if (fSentencesInit != 0) {
    local_44[0] = '\0';
    if ((fSentencesInit != 0) && (param_2 != (char *)0x0)) {
      if (rgsentenceg._16_4_ != 0) {
        iVar2 = 0;
        do {
          iVar1 = strcmp(param_2,rgsentenceg + iVar2 * 0x34);
          if (iVar1 == 0) goto LAB_000f2538;
          iVar2 = iVar2 + 1;
        } while (*(int *)(rgsentenceg + iVar2 * 0x34 + 0x10) != 0);
      }
      iVar2 = -1;
LAB_000f2538:
      if (-1 < iVar2) {
        iVar2 = USENTENCEG_Pick__FiPc(iVar2,local_44);
        if (iVar2 < 0) {
          return iVar2;
        }
        if (local_44[0] != '\0') {
          EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,param_3,param_4,param_5,param_6);
          return iVar2;
        }
        return iVar2;
      }
    }
    (*DAT_0019f794)(1,"No such sentence group %s\n",param_2);
  }
  return -1;
}


// SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii  @ 000f0880
uint SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
               (undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_54;
  char local_4c [8];
  ushort local_44 [32];
  
  if (((fSentencesInit == 0) || (local_44[0] = local_44[0] & 0xff00, fSentencesInit == 0)) ||
     (param_2 == (char *)0x0)) {
    return 0xffffffff;
  }
  if (rgsentenceg._16_4_ != 0) {
    iVar2 = 0;
    do {
      iVar1 = strcmp(param_2,rgsentenceg + iVar2 * 0x34);
      if (iVar1 == 0) goto LAB_000f090a;
      iVar2 = iVar2 + 1;
    } while (*(int *)(rgsentenceg + iVar2 * 0x34 + 0x10) != 0);
  }
  iVar2 = -1;
LAB_000f090a:
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  local_54 = param_7;
  if (fSentencesInit == 0) {
    return 0xffffffff;
  }
  if (rgsentenceg[iVar2 * 0x34 + 0x10] == 0) {
    return 0xffffffff;
  }
  uVar3 = (uint)(byte)rgsentenceg[iVar2 * 0x34 + 0x10];
  if ((int)uVar3 <= param_7) {
    local_54 = uVar3 - 1;
  }
  local_44[0] = 0x21;
  strcat((char *)local_44,rgsentenceg + iVar2 * 0x34);
  sprintf(local_4c,"%d",local_54);
  strcat((char *)local_44,local_4c);
  if (local_54 < (int)uVar3) {
    uVar3 = local_54 + 1;
  }
  else {
    uVar4 = 0;
    if (param_8 != 0) goto LAB_000f09b8;
  }
  uVar4 = uVar3;
  if ((int)uVar3 < 0) {
    return uVar3;
  }
LAB_000f09b8:
  if ((char)local_44[0] != '\0') {
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,param_3,param_4,param_5,param_6);
    return uVar4;
  }
  return uVar4;
}


// SENTENCEG_Stop__FP7edict_sii  @ 000f2424
void SENTENCEG_Stop__FP7edict_sii(undefined4 param_1,int param_2,int param_3)

{
  char local_4c [8];
  undefined2 local_44 [32];
  
  if (((fSentencesInit != 0) && (-1 < param_2)) && (-1 < param_3)) {
    local_44[0] = 0x21;
    strcat((char *)local_44,rgsentenceg + param_2 * 0x34);
    sprintf(local_4c,"%d",param_3);
    strcat((char *)local_44,local_4c);
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,0,0,0x20,100);
  }
  return;
}


