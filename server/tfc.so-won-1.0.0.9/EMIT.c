// EMIT_GROUPID_SUIT__FP7edict_si  @ 000ed0d0
void EMIT_GROUPID_SUIT__FP7edict_si(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar3 = 100;
  lVar4 = (longdouble)(*DAT_001755a4)("suitvolume");
  fVar1 = (float)lVar4;
  iVar2 = (*DAT_00175628)(0,1);
  if (iVar2 != 0) {
    iVar3 = (*DAT_00175628)(0,6);
    iVar3 = iVar3 + 0x62;
  }
  if ((byte)(0.05 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.05) << 0xe) >> 8)) == 1) {
    SENTENCEG_PlayRndI__FP7edict_siffii(param_1,param_2,fVar1,0x3f4ccccd,0,iVar3);
  }
  return;
}


// EMIT_GROUPNAME_SUIT__FP7edict_sPCc  @ 000ed140
void EMIT_GROUPNAME_SUIT__FP7edict_sPCc(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar3 = 100;
  lVar4 = (longdouble)(*DAT_001755a4)("suitvolume");
  fVar1 = (float)lVar4;
  iVar2 = (*DAT_00175628)(0,1);
  if (iVar2 != 0) {
    iVar3 = (*DAT_00175628)(0,6);
    iVar3 = iVar3 + 0x62;
  }
  if ((byte)(0.05 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.05) << 0xe) >> 8)) == 1) {
    SENTENCEG_PlayRndSz__FP7edict_sPCcffii(param_1,param_2,fVar1,0x3f4ccccd,0,iVar3);
  }
  return;
}


// EMIT_SOUND_DYN__FP7edict_siPCcffii  @ 000ecfc0
void EMIT_SOUND_DYN__FP7edict_siPCcffii
               (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  char *pcVar2;
  char local_24 [32];
  
  pcVar2 = param_3;
  if ((param_3 != (char *)0x0) && (*param_3 == '!')) {
    pcVar2 = local_24;
    iVar1 = SENTENCEG_Lookup__FPCcPc(param_3,pcVar2);
    if (iVar1 < 0) {
      (*DAT_001755b4)(2,"Unable to find %s in sentences.txt\n",param_3);
      return;
    }
  }
  (*DAT_00175534)(param_1,param_2,pcVar2,param_4,param_5,param_6,param_7);
  return;
}


// EMIT_SOUND_SUIT__FP7edict_sPCc  @ 000ed050
void EMIT_SOUND_SUIT__FP7edict_sPCc(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar3 = 100;
  lVar4 = (longdouble)(*DAT_001755a4)("suitvolume");
  fVar1 = (float)lVar4;
  iVar2 = (*DAT_00175628)(0,1);
  if (iVar2 != 0) {
    iVar3 = (*DAT_00175628)(0,6);
    iVar3 = iVar3 + 0x62;
  }
  if ((byte)(0.05 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.05) << 0xe) >> 8)) == 1) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,6,param_2,fVar1,0x3f4ccccd,0,iVar3);
  }
  return;
}


