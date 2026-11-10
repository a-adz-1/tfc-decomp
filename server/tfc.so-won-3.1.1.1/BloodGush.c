// BloodGush__10CCineBlood  @ 000b31b4
void BloodGush__10CCineBlood(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  undefined1 auStack_48 [16];
  float fStack_38;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fStack_4c = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = fStack_4c;
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  fVar1 = *(float *)(*param_1 + 0x160);
  *(float *)(*param_1 + 0x160) = fVar1 - 1.0;
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    (*DAT_0019f6f8)(*(undefined4 *)(*param_1 + 0x208));
  }
  lVar4 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
  lVar5 = (longdouble)0.7;
  if ((byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1) < 0x40) {
    UTIL_RandomBloodVector__Fv(&uStack_58);
    uVar3 = (*DAT_0019f808)(0x32,0x96);
    UTIL_BloodStream__FRC6VectorT0ii(*param_1 + 8,&uStack_58,0xf7,uVar3);
  }
  else {
    UTIL_RandomBloodVector__Fv(&uStack_58);
    UTIL_BloodDrips__FRC6VectorT0ii(*param_1 + 8,&uStack_58,0xf7,10);
  }
  lVar4 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
  lVar5 = (longdouble)0.75;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    uStack_58 = 0;
    fStack_10 = 0.0;
    uStack_54 = 0;
    fStack_c = 0.0;
    uStack_50 = 0xbf800000;
    fStack_8 = -1.0;
    lVar4 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    fStack_4c = (float)((longdouble)0.6 * lVar4);
    fStack_70 = gpGlobals[0x10] * fStack_4c;
    fStack_6c = gpGlobals[0x11] * fStack_4c;
    fStack_68 = fStack_4c * gpGlobals[0x12];
    fStack_64 = fStack_70 + fStack_10;
    fStack_60 = fStack_6c + fStack_c;
    fStack_5c = fStack_68 + fStack_8;
    lVar4 = (longdouble)(*DAT_0019f80c)(0xbf800000,0x3f800000);
    fStack_4c = (float)((longdouble)0.6 * lVar4);
    fStack_10 = gpGlobals[10] * fStack_4c + fStack_64;
    fStack_c = gpGlobals[0xb] * fStack_4c + fStack_60;
    fStack_8 = fStack_4c * gpGlobals[0xc] + fStack_5c;
    fStack_70 = fStack_10 * 256.0;
    fStack_6c = fStack_c * 256.0;
    fStack_68 = fStack_8 * 256.0;
    iVar2 = *param_1;
    fStack_7c = fStack_70 + *(float *)(iVar2 + 8);
    fStack_78 = fStack_6c + *(float *)(iVar2 + 0xc);
    fStack_74 = fStack_68 + *(float *)(iVar2 + 0x10);
    uStack_50 = 0x42800000;
    uStack_58 = 0;
    uStack_54 = 0;
    fStack_5c = *(float *)(iVar2 + 0x10) + 64.0;
    fStack_64 = *(float *)(iVar2 + 8);
    fStack_60 = *(float *)(iVar2 + 0xc);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (&fStack_64,&fStack_7c,1,*(undefined4 *)(iVar2 + 0x208),auStack_48);
    if ((byte)(1.0 < fStack_38 | (byte)((ushort)((ushort)NAN(fStack_38) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_38 == 1.0) << 0xe) >> 8)) != 0x40) {
      UTIL_BloodDecalTrace__FP11TraceResulti(auStack_48,0xf7);
    }
  }
  return;
}


