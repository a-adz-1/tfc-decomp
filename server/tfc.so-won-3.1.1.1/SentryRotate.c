// SentryRotate__12CTFSentrygun  @ 000ec644
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SentryRotate__12CTFSentrygun(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x128) != 2) {
    if (1 < *(int *)(iVar2 + 0x128) - 1U) {
      *(undefined4 *)(iVar2 + 0x130) = 0;
      iVar2 = *param_1;
    }
    *(undefined4 *)(iVar2 + 0x128) = 2;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  if ((float)param_1[0x1a9] < *gpGlobals) {
    iVar2 = CheckSentry__12CTFSentrygun(param_1);
    if (iVar2 == 0) {
      return;
    }
    param_1[0x1a9] = (int)(*gpGlobals + 5.0);
  }
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x15c) != 0) {
    *(float *)(iVar2 + 0x14c) = *(float *)(iVar2 + 0x14c) - _FUN_00152058;
    iVar2 = *param_1;
    fVar1 = *(float *)(iVar2 + 0x14c);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      *(undefined4 *)(iVar2 + 0x15c) = 0;
      *(undefined4 *)(*param_1 + 0x14c) = 0;
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x150) = g_vecZero;
      *(undefined4 *)(iVar2 + 0x154) = DAT_0019f664;
      *(undefined4 *)(iVar2 + 0x158) = DAT_0019f668;
      iVar2 = *param_1;
    }
  }
  *(float *)(iVar2 + 0x104) = *gpGlobals + 0.1;
  iVar2 = FindTarget__12CTFSentrygun(param_1);
  if ((iVar2 == 0) && (iVar2 = MoveTurret__12CTFSentrygun(param_1), iVar2 == 0)) {
    uVar3 = __rf__7EHANDLE(param_1 + 0x26,0x18);
    CheckBelowBuilding__11CBaseEntityi(uVar3);
    lVar4 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
    lVar5 = (longdouble)0.1;
    if (0x3f < (byte)((lVar5 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"weapons/turridle.wav",0x3f800000,0x3f4ccccd,0,
                 100);
    }
    if (param_1[0x1a7] == 0) {
      iVar2 = param_1[0x28];
      param_1[0x1a7] = 1;
    }
    else {
      iVar2 = param_1[0x29];
      param_1[0x1a7] = 0;
    }
    param_1[0x1b0] = (int)(float)iVar2;
    lVar4 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
    lVar5 = (longdouble)0.3;
    if (0x3f < (byte)((lVar5 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
      lVar4 = (longdouble)(*DAT_0019f80c)(0xc1200000,0x41200000);
      param_1[0x1af] = (int)(float)(int)ROUND(lVar4);
    }
  }
  return;
}


