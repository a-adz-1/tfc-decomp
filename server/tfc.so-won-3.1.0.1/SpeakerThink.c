// SpeakerThink__8CSpeaker  @ 000e3a18
void SpeakerThink__8CSpeaker(int *param_1)

{
  float fVar1;
  int iVar2;
  char *unaff_ESI;
  longdouble lVar3;
  
  fVar1 = *(float *)(*param_1 + 0x160) * 0.1;
  if (_12CTalkMonster_g_talkWaitTime < *gpGlobals) {
    if (param_1[0xf6] == 0) {
      unaff_ESI = (char *)((int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1d4));
    }
    else {
      switch(param_1[0xf6]) {
      case 1:
        unaff_ESI = "C1A0_";
        break;
      case 2:
        unaff_ESI = "C1A1_";
        break;
      case 3:
        unaff_ESI = "C1A2_";
        break;
      case 4:
        unaff_ESI = "C1A3_";
        break;
      case 5:
        unaff_ESI = "C1A4_";
        break;
      case 6:
        unaff_ESI = "C2A1_";
        break;
      case 7:
        unaff_ESI = "C2A2_";
        break;
      case 8:
        unaff_ESI = "C2A3_";
        break;
      case 9:
        unaff_ESI = "C2A4_";
        break;
      case 10:
        unaff_ESI = "C2A5_";
        break;
      case 0xb:
        unaff_ESI = "C3A1_";
        break;
      case 0xc:
        unaff_ESI = "C3A2_";
      }
    }
    if (*unaff_ESI == '!') {
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,unaff_ESI,fVar1,0x3e99999a,0,100);
      *(undefined4 *)(*param_1 + 0x104) = 0;
    }
    else {
      iVar2 = SENTENCEG_PlayRndSz__FP7edict_sPCcffii
                        (*(undefined4 *)(*param_1 + 0x208),unaff_ESI,fVar1,0x3e99999a,0,100);
      if (iVar2 < 0) {
        (*DAT_001a7f34)(1,"Level Design Error!\nSPEAKER has bad sentence group name: %s\n",unaff_ESI
                       );
      }
      lVar3 = (longdouble)(*DAT_001a7fac)(0x41700000,0x43070000);
      *(float *)(*param_1 + 0x104) = (float)(lVar3 + (longdouble)*gpGlobals);
      _12CTalkMonster_g_talkWaitTime = *gpGlobals + 5.0;
    }
  }
  else {
    lVar3 = (longdouble)(*DAT_001a7fac)(0x40a00000,0x41200000);
    *(float *)(*param_1 + 0x104) = (float)(lVar3 + (longdouble)_12CTalkMonster_g_talkWaitTime);
  }
  return;
}


