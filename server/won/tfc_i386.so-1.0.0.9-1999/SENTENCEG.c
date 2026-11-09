// SENTENCEG_GetIndex__FPCc  @ 000ec930
int SENTENCEG_GetIndex__FPCc(char *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((fSentencesInit != 0) && (param_1 != (char *)0x0)) {
    iVar2 = 0;
    iVar1 = rgsentenceg._16_4_;
    while (iVar1 != 0) {
      iVar1 = strcmp(param_1,rgsentenceg + iVar2 * 0x34);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar1 = *(int *)(rgsentenceg + iVar2 * 0x34 + 0x10);
    }
  }
  return -1;
}


// SENTENCEG_Init__Fv  @ 000ecbd0
void SENTENCEG_Init__Fv(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__src;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int local_250;
  undefined4 local_24c;
  undefined4 local_248;
  char local_244 [63];
  char acStack_205 [513];
  
  if (fSentencesInit == 0) {
    memset(gszallsentencenames,0,0x6000);
    gcallsentences = 0;
    memset(rgsentenceg,0,0x28a0);
    memset(acStack_205 + 1,0,0x200);
    memset(local_244,0,0x40);
    local_250 = -1;
    local_24c = 0;
    iVar3 = (*DAT_0017563c)("sound/sentences.txt",&local_248);
    if (iVar3 != 0) {
      pcVar9 = acStack_205 + 1;
LAB_000ece98:
      iVar5 = memfgets__FPUciRiPci(iVar3,local_248,&local_24c,pcVar9,0x1ff);
      if (iVar5 != 0) {
        iVar5 = 0;
        if (acStack_205[1] == ' ') {
          iVar4 = 0;
          do {
            iVar5 = iVar4 + 1;
            iVar7 = iVar4 + 2;
            iVar4 = iVar5;
          } while (acStack_205[iVar7] == ' ');
        }
        if ((((acStack_205[iVar5 + 1] != '\0') && (acStack_205[iVar5 + 1] != '/')) &&
            (iVar4 = isalpha((int)acStack_205[iVar5 + 1]), iVar4 != 0)) &&
           (iVar4 = iVar5, acStack_205[iVar5 + 1] != '\0')) {
          do {
            iVar7 = iVar4;
            if (acStack_205[iVar4 + 1] == ' ') break;
            iVar7 = iVar4 + 1;
            iVar2 = iVar4 + 2;
            iVar4 = iVar7;
          } while (acStack_205[iVar2] != '\0');
          if (pcVar9[iVar7] != '\0') {
            if (0x600 < gcallsentences) {
              pcVar9 = "Too many sentences in sentences.txt!\n";
LAB_000ece12:
              (*DAT_001755b4)(4,pcVar9);
              goto LAB_000ececb;
            }
            pcVar9[iVar7] = '\0';
            __src = pcVar9 + iVar5;
            uVar6 = 0xffffffff;
            pcVar8 = __src;
            do {
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              cVar1 = *pcVar8;
              pcVar8 = pcVar8 + 1;
            } while (cVar1 != '\0');
            if (0xf < ~uVar6 - 1) {
              (*DAT_001755b4)(3,"Sentence %s longer than %d letters\n",__src,0xf);
            }
            iVar4 = gcallsentences * 0x10;
            gcallsentences = gcallsentences + 1;
            strcpy(gszallsentencenames + iVar4,__src);
            iVar7 = iVar7 + -1;
            if ((iVar5 < iVar7) && (iVar4 = isdigit((int)pcVar9[iVar7]), iVar4 != 0)) {
              for (; iVar5 < iVar7; iVar7 = iVar7 + -1) {
                iVar4 = isdigit((int)acStack_205[iVar7 + 1]);
                if (iVar4 == 0) {
                  if (iVar5 < iVar7) {
                    acStack_205[iVar7 + 2] = '\0';
                    iVar4 = strcmp(local_244,pcVar9 + iVar5);
                    if (iVar4 == 0) {
                      if (-1 < local_250) {
                        *(int *)(rgsentenceg + local_250 * 0x34 + 0x10) =
                             *(int *)(rgsentenceg + local_250 * 0x34 + 0x10) + 1;
                      }
                    }
                    else {
                      local_250 = local_250 + 1;
                      if (199 < local_250) {
                        pcVar9 = "Too many sentence groups in sentences.txt!\n";
                        goto LAB_000ece12;
                      }
                      strcpy(rgsentenceg + local_250 * 0x34,pcVar9 + iVar5);
                      *(undefined4 *)(rgsentenceg + local_250 * 0x34 + 0x10) = 1;
                      strcpy(local_244,pcVar9 + iVar5);
                    }
                  }
                  break;
                }
              }
            }
          }
        }
        goto LAB_000ece98;
      }
LAB_000ececb:
      (*DAT_00175640)(iVar3);
      fSentencesInit = 1;
      iVar5 = 0;
      iVar3 = rgsentenceg._16_4_;
      while ((iVar3 != 0 && (iVar5 < 200))) {
        USENTENCEG_InitLRU__FPUci
                  (iVar5 * 0x34 + 0x17db14,*(undefined4 *)(rgsentenceg + iVar5 * 0x34 + 0x10));
        iVar5 = iVar5 + 1;
        iVar3 = *(int *)(rgsentenceg + iVar5 * 0x34 + 0x10);
      }
    }
  }
  return;
}


// SENTENCEG_Lookup__FPCcPc  @ 000ecf40
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


// SENTENCEG_PlayRndI__FP7edict_siffii  @ 000ec9b0
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


// SENTENCEG_PlayRndSz__FP7edict_sPCcffii  @ 000eca20
int SENTENCEG_PlayRndSz__FP7edict_sPCcffii
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  char local_44 [64];
  
  if (fSentencesInit == 0) {
    iVar1 = -1;
  }
  else {
    local_44[0] = '\0';
    iVar1 = SENTENCEG_GetIndex__FPCc(param_2);
    if (iVar1 < 0) {
      (*DAT_001755b4)(1,"No such sentence group %s\n",param_2);
      iVar1 = -1;
    }
    else {
      iVar1 = USENTENCEG_Pick__FiPc(iVar1,local_44);
      if ((-1 < iVar1) && (local_44[0] != '\0')) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,param_3,param_4,param_5,param_6);
      }
    }
  }
  return iVar1;
}


// SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii  @ 000ecac0
int SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  char local_44 [64];
  
  if (fSentencesInit != 0) {
    local_44[0] = '\0';
    iVar1 = SENTENCEG_GetIndex__FPCc(param_2);
    if (-1 < iVar1) {
      iVar1 = USENTENCEG_PickSequential__FiPcii(iVar1,local_44,param_7,param_8);
      if (iVar1 < 0) {
        return iVar1;
      }
      if (local_44[0] == '\0') {
        return iVar1;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,param_3,param_4,param_5,param_6);
      return iVar1;
    }
  }
  return -1;
}


// SENTENCEG_Stop__FP7edict_sii  @ 000ecb50
void SENTENCEG_Stop__FP7edict_sii(undefined4 param_1,int param_2,int param_3)

{
  char local_4c [8];
  char local_44 [64];
  
  if (((fSentencesInit != 0) && (-1 < param_2)) && (-1 < param_3)) {
    local_44[0] = '!';
    local_44[1] = '\0';
    strcat(local_44,rgsentenceg + param_2 * 0x34);
    sprintf(local_4c,"%d",param_3);
    strcat(local_44,local_4c);
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,0,0,0x20,100);
  }
  return;
}


