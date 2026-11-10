// FailedSpamCheck__FP7edict_si  @ 0008f574
undefined4 FailedSpamCheck__FP7edict_si(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  char local_40 [60];
  
  if ((param_1 == 0) && (param_1 = (*DAT_0019f7b4)(0), param_1 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(param_1 + 0x7c);
  }
  if (piVar5 != (int *)0x0) {
    fVar1 = (float)piVar5[0x36e];
    fVar2 = *gpGlobals;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      fVar1 = fVar1 + (float)tfc_spam_penalty2._12_4_;
      piVar5[0x36e] = (int)fVar1;
      sprintf(local_40,"You may not speak for %d seconds for spamming.\n",
              (int)ROUND(fVar1 - *gpGlobals));
      (*DAT_0019f758)(1,gmsgSayText,0,*(undefined4 *)(*piVar5 + 0x208));
      uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(*piVar5 + 0x208));
      (*DAT_0019f760)(uVar4);
      (*DAT_0019f778)(local_40);
      (*DAT_0019f75c)();
      piVar5[0x36f] = (int)*gpGlobals;
      return 1;
    }
    if ((byte)(-1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -1.0) << 0xe) >> 8)) != 0x40) {
      piVar5[0x370] = 0;
      piVar5[0x36e] = -0x40800000;
    }
    fVar1 = *gpGlobals - (float)piVar5[0x36f];
    if ((byte)((2.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 2.0) << 0xe) >> 8)) - 1) < 0x40) {
      iVar3 = piVar5[0x370];
      piVar5[0x370] = (int)ROUND((float)iVar3 - fVar1);
      if ((int)ROUND((float)iVar3 - fVar1) < 0) {
        piVar5[0x370] = 0;
      }
    }
    else {
      iVar3 = piVar5[0x370];
      piVar5[0x370] = iVar3 + 1;
      if (param_2 == 0) {
        piVar5[0x370] = iVar3 + 2;
      }
    }
    if ((float)tfc_spam_limit._12_4_ < (float)piVar5[0x370]) {
      piVar5[0x36e] = (int)(*gpGlobals + (float)tfc_spam_penalty1._12_4_);
      return 1;
    }
  }
  return 0;
}


