// EMIT_GROUPID_SUIT__FP7edict_si  @ 000e2e0c
void EMIT_GROUPID_SUIT__FP7edict_si(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar2 = 100;
  lVar3 = (longdouble)(*DAT_001a7f24)("suitvolume");
  iVar1 = (*DAT_001a7fa8)(0,1);
  if (iVar1 != 0) {
    iVar2 = (*DAT_001a7fa8)(0,6);
    iVar2 = iVar2 + 0x62;
  }
  if (0.05 < (float)lVar3) {
    SENTENCEG_PlayRndI__FP7edict_siffii(param_1,param_2,(float)lVar3,0x3f4ccccd,0,iVar2);
  }
  return;
}


// EMIT_GROUPNAME_SUIT__FP7edict_sPCc  @ 000e2ea0
void EMIT_GROUPNAME_SUIT__FP7edict_sPCc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar2 = 100;
  lVar3 = (longdouble)(*DAT_001a7f24)("suitvolume");
  iVar1 = (*DAT_001a7fa8)(0,1);
  if (iVar1 != 0) {
    iVar2 = (*DAT_001a7fa8)(0,6);
    iVar2 = iVar2 + 0x62;
  }
  if (0.05 < (float)lVar3) {
    SENTENCEG_PlayRndSz__FP7edict_sPCcffii(param_1,param_2,(float)lVar3,0x3f4ccccd,0,iVar2);
  }
  return;
}


// EMIT_SOUND_DYN__FP7edict_siPCcffii  @ 000e2cd4
void EMIT_SOUND_DYN__FP7edict_siPCcffii
               (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  char *pcVar2;
  char local_20 [32];
  
  pcVar2 = param_3;
  if ((param_3 != (char *)0x0) && (*param_3 == '!')) {
    pcVar2 = local_20;
    iVar1 = SENTENCEG_Lookup__FPCcPc(param_3,pcVar2);
    if (iVar1 < 0) {
      (*DAT_001a7f34)(2,"Unable to find %s in sentences.txt\n",param_3);
      return;
    }
  }
  (*DAT_001a7eb4)(param_1,param_2,pcVar2,param_4,param_5,param_6,param_7);
  return;
}


// EMIT_SOUND_SUIT__FP7edict_sPCc  @ 000e2d74
void EMIT_SOUND_SUIT__FP7edict_sPCc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar2 = 100;
  lVar3 = (longdouble)(*DAT_001a7f24)("suitvolume");
  iVar1 = (*DAT_001a7fa8)(0,1);
  if (iVar1 != 0) {
    iVar2 = (*DAT_001a7fa8)(0,6);
    iVar2 = iVar2 + 0x62;
  }
  if (0.05 < (float)lVar3) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,6,param_2,(float)lVar3,0x3f4ccccd,0,iVar2);
  }
  return;
}


