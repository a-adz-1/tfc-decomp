// FollowTarget__14CTriggerCamera  @ 00117340
void FollowTarget__14CTriggerCamera(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  
  piVar7 = param_1 + 0x118;
  iVar4 = __opP11CBaseEntity__7EHANDLE(piVar7);
  if (iVar4 != 0) {
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11a);
    if (iVar4 != 0) {
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x11f];
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        piVar7 = (int *)__rf__7EHANDLE(param_1 + 0x11a);
        iVar4 = *piVar7;
        iVar3 = *param_1;
        fStack_1c = *(float *)(iVar4 + 8) - *(float *)(iVar3 + 8);
        fStack_18 = *(float *)(iVar4 + 0xc) - *(float *)(iVar3 + 0xc);
        fStack_14 = *(float *)(iVar4 + 0x10) - *(float *)(iVar3 + 0x10);
        UTIL_VecToAngles__FRC6Vector(&fStack_10,&fStack_1c);
        fStack_10 = -fStack_10;
        iVar4 = *param_1;
        fVar1 = *(float *)(iVar4 + 0x54);
        if (0x3f < (byte)((fVar1 < 360.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1)) {
          *(float *)(iVar4 + 0x54) = fVar1 - 360.0;
          iVar4 = *param_1;
        }
        fVar1 = *(float *)(iVar4 + 0x54);
        if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
          *(float *)(iVar4 + 0x54) = fVar1 + 360.0;
          iVar4 = *param_1;
        }
        fVar1 = fStack_10 - *(float *)(iVar4 + 0x50);
        fStack_c = fStack_c - *(float *)(iVar4 + 0x54);
        if (0x3f < (byte)((-180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == -180.0) << 0xe) >> 8)) - 1)) {
          fVar1 = fVar1 + 360.0;
        }
        if (180.0 < fVar1) {
          fVar1 = fVar1 - 360.0;
        }
        if (fStack_c < -180.0) {
          fStack_c = fStack_c + 360.0;
        }
        if (0x3f < (byte)((fStack_c < 180.0 | (byte)((ushort)((ushort)NAN(fStack_c) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fStack_c == 180.0) << 0xe) >> 8)) - 1)) {
          fStack_c = fStack_c - 360.0;
        }
        *(float *)(iVar4 + 0x5c) = gpGlobals[1] * 40.0 * fVar1;
        *(float *)(*param_1 + 0x60) = gpGlobals[1] * 40.0 * fStack_c;
        iVar4 = *param_1;
        if ((*(byte *)(iVar4 + 0x1a0) & 4) == 0) {
          fStack_18 = *(float *)(iVar4 + 0x24) * 0.8;
          fStack_14 = *(float *)(iVar4 + 0x28) * 0.8;
          *(float *)(iVar4 + 0x20) = *(float *)(iVar4 + 0x20) * 0.8;
          *(float *)(iVar4 + 0x24) = fStack_18;
          *(float *)(iVar4 + 0x28) = fStack_14;
          iVar4 = *param_1;
          fStack_1c = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                           *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                           *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20));
          if (0x3f < (byte)((10.0 < fStack_1c | (byte)((ushort)((ushort)NAN(fStack_1c) << 10) >> 8)
                            | (byte)((ushort)((ushort)(fStack_1c == 10.0) << 0xe) >> 8)) - 1)) {
            *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
            *(undefined4 *)(iVar4 + 0x24) = DAT_0019f664;
            *(undefined4 *)(iVar4 + 0x28) = DAT_0019f668;
          }
        }
        *(float *)(*param_1 + 0x104) = *gpGlobals;
        Move__14CTriggerCamera(param_1);
        return;
      }
    }
    iVar4 = __rf__7EHANDLE(piVar7);
    iVar4 = (**(code **)(*(int *)(iVar4 + 0x454) + 0x8c))(iVar4);
    if (iVar4 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(piVar7);
      piVar5 = (int *)__rf__7EHANDLE(piVar7,*(undefined4 *)(*piVar5 + 0x208));
      (*DAT_0019f810)(*(undefined4 *)(*piVar5 + 0x208));
      uVar6 = __opP11CBaseEntity__7EHANDLE(piVar7,1);
      EnableControl__11CBasePlayeri(uVar6);
    }
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    iVar4 = *param_1;
    *(undefined4 *)(iVar4 + 0x5c) = 0;
    *(undefined4 *)(iVar4 + 0x60) = 0;
    *(undefined4 *)(iVar4 + 100) = 0;
    param_1[0x126] = 0;
  }
  return;
}


