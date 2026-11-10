// SENTENCEG_GetIndex__FPCc  @ 000ef014
int SENTENCEG_GetIndex__FPCc(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((fSentencesInit != 0) && (param_1 != (char *)0x0)) && (iVar3 = 0, rgsentenceg._16_4_ != 0)) {
    iVar2 = 0;
    do {
      iVar1 = strcmp(param_1,rgsentenceg + iVar2);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar2 + 0x44;
      iVar2 = iVar2 + 0x34;
    } while (*(int *)(rgsentenceg + iVar1) != 0);
  }
  return -1;
}


// SENTENCEG_Init__Fv  @ 000ef2d4
void SENTENCEG_Init__Fv(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__src;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  int *piVar9;
  int local_25c;
  int local_24c;
  undefined4 local_248;
  undefined4 local_244;
  char local_240 [63];
  char acStack_201 [513];
  
  if (fSentencesInit == 0) {
    memset(gszallsentencenames,0,0x6000);
    gcallsentences = 0;
    memset(rgsentenceg,0,0x28a0);
    pcVar8 = acStack_201 + 1;
    memset(pcVar8,0,0x200);
    memset(local_240,0,0x40);
    local_24c = -1;
    local_248 = 0;
    iVar2 = (*DAT_001c119c)("sound/sentences.txt",&local_244);
    if (iVar2 != 0) {
      local_25c = -0x34;
LAB_000ef5c7:
      iVar5 = memfgets__FPUciRiPci(iVar2,local_244,&local_248,pcVar8,0x1ff);
      if (iVar5 != 0) {
        iVar5 = 0;
        cVar1 = acStack_201[1];
        while (cVar1 == ' ') {
          cVar1 = acStack_201[iVar5 + 2];
          iVar5 = iVar5 + 1;
        }
        if ((((acStack_201[iVar5 + 1] != '\0') && (acStack_201[iVar5 + 1] != '/')) &&
            (iVar3 = isalpha((int)acStack_201[iVar5 + 1]), iVar3 != 0)) &&
           (acStack_201[iVar5 + 1] != '\0')) {
          pcVar7 = acStack_201 + iVar5 + 1;
          iVar3 = iVar5;
          do {
            if (*pcVar7 == ' ') break;
            pcVar7 = pcVar7 + 1;
            iVar3 = iVar3 + 1;
          } while (*pcVar7 != '\0');
          if (pcVar8[iVar3] != '\0') {
            if (0x600 < gcallsentences) {
              pcVar8 = "Too many sentences in sentences.txt!\n";
LAB_000ef548:
              (*DAT_001c1114)(4,pcVar8);
              goto LAB_000ef5f8;
            }
            pcVar8[iVar3] = '\0';
            __src = pcVar8 + iVar5;
            uVar6 = 0xffffffff;
            pcVar7 = __src;
            do {
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar7 + 1;
            } while (cVar1 != '\0');
            if (0xf < ~uVar6 - 1) {
              (*DAT_001c1114)(3,"Sentence %s longer than %d letters\n",__src,0xf);
            }
            iVar4 = gcallsentences * 0x10;
            gcallsentences = gcallsentences + 1;
            strcpy(gszallsentencenames + iVar4,__src);
            iVar3 = iVar3 + -1;
            if ((iVar5 < iVar3) && (iVar4 = isdigit((int)pcVar8[iVar3]), iVar4 != 0)) {
              for (; iVar5 < iVar3; iVar3 = iVar3 + -1) {
                iVar4 = isdigit((int)acStack_201[iVar3 + 1]);
                if (iVar4 == 0) {
                  if (iVar5 < iVar3) {
                    acStack_201[iVar3 + 2] = '\0';
                    iVar3 = strcmp(local_240,pcVar8 + iVar5);
                    if (iVar3 == 0) {
                      if (-1 < local_24c) {
                        *(int *)(rgsentenceg + local_25c + 0x10) =
                             *(int *)(rgsentenceg + local_25c + 0x10) + 1;
                      }
                    }
                    else {
                      local_24c = local_24c + 1;
                      if (199 < local_24c) {
                        pcVar8 = "Too many sentence groups in sentences.txt!\n";
                        goto LAB_000ef548;
                      }
                      strcpy(rgsentenceg + local_25c + 0x34,pcVar8 + iVar5);
                      *(undefined4 *)(rgsentenceg + local_25c + 0x44) = 1;
                      strcpy(local_240,pcVar8 + iVar5);
                      local_25c = local_25c + 0x34;
                    }
                  }
                  break;
                }
              }
            }
          }
        }
        goto LAB_000ef5c7;
      }
LAB_000ef5f8:
      (*DAT_001c11a0)(iVar2);
      fSentencesInit = 1;
      if (rgsentenceg._16_4_ != 0) {
        piVar9 = (int *)(rgsentenceg + 0x10);
        iVar2 = 0;
        do {
          if (0x1cbf3c < (int)piVar9) {
            return;
          }
          USENTENCEG_InitLRU__FPUci(iVar2 + 0x1c96d4,*piVar9);
          piVar9 = piVar9 + 0xd;
          iVar2 = iVar2 + 0x34;
        } while (*piVar9 != 0);
      }
    }
  }
  return;
}


// SENTENCEG_Lookup__FPCcPc  @ 000ef66c
int SENTENCEG_Lookup__FPCcPc(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_8 [8];
  
  if (0 < gcallsentences) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = strcasecmp(gszallsentencenames + iVar3,(char *)(param_1 + 1));
      if (iVar1 == 0) {
        if (param_2 == (char *)0x0) {
          return iVar2;
        }
        param_2[0] = '!';
        param_2[1] = '\0';
        sprintf(local_8,"%d",iVar2);
        strcat(param_2,local_8);
        return iVar2;
      }
      iVar3 = iVar3 + 0x10;
      iVar2 = iVar2 + 1;
    } while (iVar2 < gcallsentences);
  }
  return -1;
}


// SENTENCEG_PlayRndI__FP7edict_siffii  @ 000ef084
int SENTENCEG_PlayRndI__FP7edict_siffii
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined1 local_40 [64];
  
  if (fSentencesInit == 0) {
    iVar1 = -1;
  }
  else {
    local_40[0] = 0;
    iVar1 = USENTENCEG_Pick__FiPc(param_2,local_40);
    if (0 < iVar1) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_40,param_3,param_4,param_5,param_6);
    }
  }
  return iVar1;
}


// SENTENCEG_PlayRndSz__FP7edict_sPCcffii  @ 000ef0fc
void SENTENCEG_PlayRndSz__FP7edict_sPCcffii(void)

{
  FUN_000ef107();
  return;
}


// SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii  @ 000ef1ac
int SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  char local_40 [64];
  
  if (fSentencesInit != 0) {
    local_40[0] = '\0';
    iVar1 = SENTENCEG_GetIndex__FPCc(param_2);
    if (-1 < iVar1) {
      iVar1 = USENTENCEG_PickSequential__FiPcii(iVar1,local_40,param_7,param_8);
      if (iVar1 < 0) {
        return iVar1;
      }
      if (local_40[0] == '\0') {
        return iVar1;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_40,param_3,param_4,param_5,param_6);
      return iVar1;
    }
  }
  return -1;
}


// SENTENCEG_Stop__FP7edict_sii  @ 000ef244
void SENTENCEG_Stop__FP7edict_sii(undefined4 param_1,int param_2,int param_3)

{
  char acStack_48 [8];
  undefined2 local_40 [32];
  
  if (((fSentencesInit != 0) && (-1 < param_2)) && (-1 < param_3)) {
    local_40[0] = 0x21;
    strcat((char *)local_40,rgsentenceg + param_2 * 0x34);
    sprintf(acStack_48,"%d",param_3);
    strcat((char *)local_40,acStack_48);
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_40,0,0,0x20,100);
  }
  return;
}


