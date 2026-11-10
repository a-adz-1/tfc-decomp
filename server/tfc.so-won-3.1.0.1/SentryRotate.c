// SentryRotate__12CTFSentrygun  @ 000de9dc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SentryRotate__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  longdouble lVar6;
  
  SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM(param_1,2);
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x189];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    iVar3 = CheckSentry__12CTFSentrygun(param_1);
    if (iVar3 == 0) {
      return;
    }
    param_1[0x189] = (int)(*gpGlobals + 5.0);
  }
  if (*(int *)(*param_1 + 0x15c) != 0) {
    CheckShield__12CTFSentrygun(param_1);
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  iVar3 = FindTarget__12CTFSentrygun(param_1);
  if ((iVar3 == 0) && (iVar3 = MoveTurret__12CTFSentrygun(param_1), iVar3 == 0)) {
    uVar4 = __rf__7EHANDLE(param_1 + 0x26,0x18);
    CheckBelowBuilding__11CBaseEntityi(uVar4);
    lVar5 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
    lVar6 = (longdouble)0.1;
    if (0x3f < (byte)((lVar6 < lVar5 |
                       (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1)) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"weapons/turridle.wav",0x3f800000,0x3f4ccccd,0,
                 100);
    }
    if (param_1[0x187] == 0) {
      param_1[0x187] = 1;
      iVar3 = param_1[0x28];
    }
    else {
      param_1[0x187] = 0;
      iVar3 = param_1[0x29];
    }
    param_1[400] = (int)(float)iVar3;
    lVar5 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
    lVar6 = (longdouble)_FUN_0013c330;
    if (0x3f < (byte)((lVar6 < lVar5 |
                       (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1)) {
      lVar5 = (longdouble)(*DAT_001a7fac)(0xc1200000,0x41200000);
      param_1[399] = (int)(float)(int)ROUND(lVar5);
    }
  }
  return;
}


