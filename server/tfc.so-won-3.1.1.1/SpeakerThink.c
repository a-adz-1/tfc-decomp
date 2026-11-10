// SpeakerThink__8CSpeaker  @ 000f1b88
void SpeakerThink__8CSpeaker(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  char *unaff_EDI;
  longdouble lVar6;
  char acStack_48 [68];
  
  fVar3 = *(float *)(*param_1 + 0x160) * 0.1;
  fVar1 = *gpGlobals;
  if ((byte)(_12CTalkMonster_g_talkWaitTime < fVar1 |
             (byte)((ushort)((ushort)(NAN(_12CTalkMonster_g_talkWaitTime) || NAN(fVar1)) << 10) >> 8
                   ) |
            (byte)((ushort)((ushort)(_12CTalkMonster_g_talkWaitTime == fVar1) << 0xe) >> 8)) != 1) {
    lVar6 = (longdouble)(*DAT_0019f80c)(0x40a00000,0x41200000);
    *(float *)(*param_1 + 0x104) = (float)(lVar6 + (longdouble)_12CTalkMonster_g_talkWaitTime);
    return;
  }
  if (param_1[0x116] == 0) {
    unaff_EDI = (char *)(*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26]);
  }
  else {
    switch(param_1[0x116]) {
    case 1:
      unaff_EDI = "C1A0_";
      break;
    case 2:
      unaff_EDI = "C1A1_";
      break;
    case 3:
      unaff_EDI = "C1A2_";
      break;
    case 4:
      unaff_EDI = "C1A3_";
      break;
    case 5:
      unaff_EDI = "C1A4_";
      break;
    case 6:
      unaff_EDI = "C2A1_";
      break;
    case 7:
      unaff_EDI = "C2A2_";
      break;
    case 8:
      unaff_EDI = "C2A3_";
      break;
    case 9:
      unaff_EDI = "C2A4_";
      break;
    case 10:
      unaff_EDI = "C2A5_";
      break;
    case 0xb:
      unaff_EDI = "C3A1_";
      break;
    case 0xc:
      unaff_EDI = "C3A2_";
    }
  }
  if (*unaff_EDI == '!') {
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,unaff_EDI,fVar3,0x3e99999a,0,100);
    *(undefined4 *)(*param_1 + 0x104) = 0;
    return;
  }
  uVar2 = *(undefined4 *)(*param_1 + 0x208);
  if (fSentencesInit != 0) {
    acStack_48[0] = '\0';
    if ((fSentencesInit == 0) || (unaff_EDI == (char *)0x0)) {
LAB_000f1d7d:
      (*DAT_0019f794)(1,"No such sentence group %s\n",unaff_EDI);
      iVar5 = -1;
    }
    else {
      if (rgsentenceg._16_4_ != 0) {
        iVar5 = 0;
        do {
          iVar4 = strcmp(unaff_EDI,rgsentenceg + iVar5 * 0x34);
          if (iVar4 == 0) goto LAB_000f1d79;
          iVar5 = iVar5 + 1;
        } while (*(int *)(rgsentenceg + iVar5 * 0x34 + 0x10) != 0);
      }
      iVar5 = -1;
LAB_000f1d79:
      if (iVar5 < 0) goto LAB_000f1d7d;
      iVar5 = USENTENCEG_Pick__FiPc(iVar5,acStack_48);
      if ((-1 < iVar5) && (acStack_48[0] != '\0')) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar2,2,acStack_48,fVar3,0x3e99999a,0,100);
      }
    }
    if (-1 < iVar5) goto LAB_000f1df7;
  }
  (*DAT_0019f794)(1,FUN_00152b00,unaff_EDI);
LAB_000f1df7:
  lVar6 = (longdouble)(*DAT_0019f80c)(0x41700000,0x43070000);
  *(float *)(*param_1 + 0x104) = (float)(lVar6 + (longdouble)*gpGlobals);
  _12CTalkMonster_g_talkWaitTime = *gpGlobals + 5.0;
  return;
}


