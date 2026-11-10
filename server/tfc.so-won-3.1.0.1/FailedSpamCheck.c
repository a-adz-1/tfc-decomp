// FailedSpamCheck__FP7edict_si  @ 00087ad8
undefined4 FailedSpamCheck__FP7edict_si(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int *piVar5;
  char local_3c [60];
  
  if ((param_1 == 0) && (param_1 = (*DAT_001a7f54)(0), param_1 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(param_1 + 0x7c);
  }
  if (piVar5 != (int *)0x0) {
    fVar2 = (float)piVar5[0x347];
    fVar3 = *gpGlobals;
    if (0x3f < (byte)((fVar2 < fVar3 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
      fVar2 = fVar2 + (float)tfc_spam_penalty2._12_4_;
      piVar5[0x347] = (int)fVar2;
      sprintf(local_3c,"You may not speak for %d seconds for spamming.\n",
              (int)ROUND(fVar2 - *gpGlobals));
      (*DAT_001a7ef8)(1,gmsgSayText,0,*(undefined4 *)(*piVar5 + 0x208));
      uVar4 = (*DAT_001a7f5c)(*(undefined4 *)(*piVar5 + 0x208));
      (*DAT_001a7f00)(uVar4);
      (*DAT_001a7f18)(local_3c);
      (*DAT_001a7efc)();
      piVar5[0x348] = (int)*gpGlobals;
      return 1;
    }
    fVar2 = (float)piVar5[0x347];
    if ((byte)(-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) != 0x40) {
      piVar5[0x349] = 0;
      piVar5[0x347] = -0x40800000;
    }
    fVar2 = *gpGlobals - (float)piVar5[0x348];
    if ((byte)((2.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 2.0) << 0xe) >> 8)) - 1) < 0x40) {
      iVar1 = (int)ROUND((float)piVar5[0x349] - (*gpGlobals - (float)piVar5[0x348]));
      piVar5[0x349] = iVar1;
      if (iVar1 < 0) {
        piVar5[0x349] = 0;
      }
    }
    else {
      piVar5[0x349] = piVar5[0x349] + 1;
      if (param_2 == 0) {
        piVar5[0x349] = piVar5[0x349] + 1;
      }
    }
    fVar2 = (float)piVar5[0x349];
    if (0x3f < (byte)((fVar2 < (float)tfc_spam_limit._12_4_ |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN((float)tfc_spam_limit._12_4_)) <<
                                      10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == (float)tfc_spam_limit._12_4_) << 0xe) >> 8))
                     - 1)) {
      piVar5[0x347] = (int)(*gpGlobals + (float)tfc_spam_penalty1._12_4_);
      return 1;
    }
  }
  return 0;
}


