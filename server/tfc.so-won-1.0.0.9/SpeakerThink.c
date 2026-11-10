// SpeakerThink__8CSpeaker  @ 000edb70
void SpeakerThink__8CSpeaker(int *param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  char *unaff_EBX;
  longdouble lVar5;
  
  fVar2 = *(float *)(*param_1 + 0x140) * 0.1;
  fVar1 = *gpGlobals;
  if ((byte)((fVar1 < _12CTalkMonster_g_talkWaitTime |
              (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_12CTalkMonster_g_talkWaitTime)) << 10) >>
                    8) |
             (byte)((ushort)((ushort)(fVar1 == _12CTalkMonster_g_talkWaitTime) << 0xe) >> 8)) - 1) <
      0x40) {
    lVar5 = (longdouble)(*DAT_0017562c)(0x40a00000,0x41200000);
    *(float *)(*param_1 + 0xe4) = (float)(lVar5 + (longdouble)_12CTalkMonster_g_talkWaitTime);
  }
  else {
    if (param_1[0xf3] == 0) {
      unaff_EBX = (char *)((int)gpGlobals[0x26] + *(int *)(*param_1 + 0x1b4));
    }
    else {
      switch(param_1[0xf3]) {
      case 1:
        unaff_EBX = "C1A0_";
        break;
      case 2:
        unaff_EBX = "C1A1_";
        break;
      case 3:
        unaff_EBX = "C1A2_";
        break;
      case 4:
        unaff_EBX = "C1A3_";
        break;
      case 5:
        unaff_EBX = "C1A4_";
        break;
      case 6:
        unaff_EBX = "C2A1_";
        break;
      case 7:
        unaff_EBX = "C2A2_";
        break;
      case 8:
        unaff_EBX = "C2A3_";
        break;
      case 9:
        unaff_EBX = "C2A4_";
        break;
      case 10:
        unaff_EBX = "C2A5_";
        break;
      case 0xb:
        unaff_EBX = "C3A1_";
        break;
      case 0xc:
        unaff_EBX = "C3A2_";
      }
    }
    if (*unaff_EBX == '!') {
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),*param_1 + 8,unaff_EBX,fVar2,0x3e99999a,0,100);
      *(undefined4 *)(*param_1 + 0xe4) = 0;
    }
    else {
      iVar4 = SENTENCEG_PlayRndSz__FP7edict_sPCcffii
                        (*(undefined4 *)(*param_1 + 0x1e8),unaff_EBX,fVar2,0x3e99999a,0,100);
      if (iVar4 < 0) {
        (*DAT_001755b4)(1,"Level Design Error!\nSPEAKER has bad sentence group name: %s\n",unaff_EBX
                       );
      }
      lVar5 = (longdouble)(*DAT_0017562c)(0x41700000,0x43070000);
      pfVar3 = gpGlobals;
      *(float *)(*param_1 + 0xe4) = (float)(lVar5 + (longdouble)*gpGlobals);
      _12CTalkMonster_g_talkWaitTime = *pfVar3 + 5.0;
    }
  }
  return;
}


