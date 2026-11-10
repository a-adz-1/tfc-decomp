// EMIT_GROUPID_SUIT__FP7edict_si  @ 000f21d4
void EMIT_GROUPID_SUIT__FP7edict_si(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  undefined1 local_44 [64];
  
  lVar3 = (longdouble)(*DAT_0019f784)("suitvolume");
  iVar2 = 100;
  iVar1 = (*DAT_0019f808)(0,1);
  if (iVar1 != 0) {
    iVar2 = (*DAT_0019f808)(0,6);
    iVar2 = iVar2 + 0x62;
  }
  if ((0.05 < (float)lVar3) && (fSentencesInit != 0)) {
    local_44[0] = 0;
    iVar1 = USENTENCEG_Pick__FiPc(param_2,local_44);
    if (0 < iVar1) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,(float)lVar3,0x3f4ccccd,0,iVar2);
    }
  }
  return;
}


// EMIT_GROUPNAME_SUIT__FP7edict_sPCc  @ 000f104c
void EMIT_GROUPNAME_SUIT__FP7edict_sPCc(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  int local_4c;
  char local_44 [64];
  
  local_4c = 100;
  lVar3 = (longdouble)(*DAT_0019f784)("suitvolume");
  iVar1 = (*DAT_0019f808)(0,1);
  if (iVar1 != 0) {
    local_4c = (*DAT_0019f808)(0,6);
    local_4c = local_4c + 0x62;
  }
  if ((0.05 < (float)lVar3) && (fSentencesInit != 0)) {
    local_44[0] = '\0';
    if ((fSentencesInit != 0) && (param_2 != (char *)0x0)) {
      if (rgsentenceg._16_4_ != 0) {
        iVar1 = 0;
        do {
          iVar2 = strcmp(param_2,rgsentenceg + iVar1 * 0x34);
          if (iVar2 == 0) goto LAB_000f1135;
          iVar1 = iVar1 + 1;
        } while (*(int *)(rgsentenceg + iVar1 * 0x34 + 0x10) != 0);
      }
      iVar1 = -1;
LAB_000f1135:
      if (-1 < iVar1) {
        iVar1 = USENTENCEG_Pick__FiPc(iVar1,local_44);
        if (iVar1 < 0) {
          return;
        }
        if (local_44[0] == '\0') {
          return;
        }
        EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,2,local_44,(float)lVar3,0x3f4ccccd,0,local_4c);
        return;
      }
    }
    (*DAT_0019f794)(1,"No such sentence group %s\n",param_2);
  }
  return;
}


// EMIT_SOUND_DYN__FP7edict_siPCcffii  @ 000f228c
void EMIT_SOUND_DYN__FP7edict_siPCcffii
               (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  char *__dest;
  int iVar2;
  char local_2c [8];
  undefined2 local_24 [16];
  
  __dest = param_3;
  if ((param_3 != (char *)0x0) && (*param_3 == '!')) {
    __dest = (char *)local_24;
    iVar2 = 0;
    if (0 < gcallsentences) {
      do {
        iVar1 = strcasecmp(gszallsentencenames + iVar2 * 0x10,param_3 + 1);
        if (iVar1 == 0) {
          local_24[0] = 0x21;
          sprintf(local_2c,"%d",iVar2);
          strcat(__dest,local_2c);
          goto LAB_000f22f9;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < gcallsentences);
    }
    iVar2 = -1;
LAB_000f22f9:
    if (iVar2 < 0) {
      (*DAT_0019f794)(2,"Unable to find %s in sentences.txt\n",param_3);
      return;
    }
  }
  (*DAT_0019f714)(param_1,param_2,__dest,param_4,param_5,param_6,param_7);
  return;
}


// EMIT_SOUND_SUIT__FP7edict_sPCc  @ 000f0ecc
void EMIT_SOUND_SUIT__FP7edict_sPCc(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *__dest;
  longdouble lVar3;
  int local_34;
  char local_2c [8];
  undefined2 local_24 [16];
  
  local_34 = 100;
  lVar3 = (longdouble)(*DAT_0019f784)("suitvolume");
  iVar1 = (*DAT_0019f808)(0,1);
  if (iVar1 != 0) {
    local_34 = (*DAT_0019f808)(0,6);
    local_34 = local_34 + 0x62;
  }
  if (0.05 < (float)lVar3) {
    __dest = param_2;
    if ((param_2 != (char *)0x0) && (*param_2 == '!')) {
      __dest = (char *)local_24;
      iVar1 = 0;
      if (0 < gcallsentences) {
        do {
          iVar2 = strcasecmp(gszallsentencenames + iVar1 * 0x10,param_2 + 1);
          if (iVar2 == 0) {
            local_24[0] = 0x21;
            sprintf(local_2c,"%d",iVar1);
            strcat(__dest,local_2c);
            goto LAB_000f0fa1;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < gcallsentences);
      }
      iVar1 = -1;
LAB_000f0fa1:
      if (iVar1 < 0) {
        (*DAT_0019f794)(2,"Unable to find %s in sentences.txt\n",param_2);
        return;
      }
    }
    (*DAT_0019f714)(param_1,6,__dest,(float)lVar3,0x3f4ccccd,0,local_34);
  }
  return;
}


