// FollowTarget__14CTriggerCamera  @ 00105774
void FollowTarget__14CTriggerCamera(int *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0xf8);
  if (iVar2 != 0) {
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0xfa);
    if ((iVar2 == 0) || ((float)param_1[0xff] < *gpGlobals)) {
      piVar5 = param_1 + 0xf8;
      iVar2 = __rf__7EHANDLE(piVar5);
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x88))(iVar2);
      if (iVar2 != 0) {
        piVar3 = (int *)__rf__7EHANDLE(piVar5);
        piVar3 = (int *)__rf__7EHANDLE(piVar5,*(undefined4 *)(*piVar3 + 0x208));
        (*DAT_001a7fb0)(*(undefined4 *)(*piVar3 + 0x208));
        uVar4 = __opP11CBaseEntity__7EHANDLE(piVar5,1);
        EnableControl__11CBasePlayeri(uVar4);
      }
      SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x5c) = 0;
      *(undefined4 *)(iVar2 + 0x60) = 0;
      *(undefined4 *)(iVar2 + 100) = 0;
      param_1[0x106] = 0;
    }
    else {
      piVar5 = (int *)__rf__7EHANDLE(param_1 + 0xfa);
      iVar2 = *piVar5;
      local_18 = *(float *)(iVar2 + 8) - *(float *)(*param_1 + 8);
      local_14 = *(float *)(iVar2 + 0xc) - *(float *)(*param_1 + 0xc);
      local_10 = *(float *)(iVar2 + 0x10) - *(float *)(*param_1 + 0x10);
      UTIL_VecToAngles__FRC6Vector(local_c,&local_18);
      local_10 = -local_10;
      iVar2 = *param_1;
      if (360.0 < *(float *)(iVar2 + 0x54)) {
        *(float *)(iVar2 + 0x54) = *(float *)(iVar2 + 0x54) - 360.0;
      }
      iVar2 = *param_1;
      fVar1 = *(float *)(iVar2 + 0x54);
      if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
        *(float *)(iVar2 + 0x54) = *(float *)(iVar2 + 0x54) + 360.0;
      }
      fVar1 = local_10 - *(float *)(*param_1 + 0x50);
      local_c[0] = local_c[0] - *(float *)(*param_1 + 0x54);
      if (0x3f < (byte)((-180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == -180.0) << 0xe) >> 8)) - 1)) {
        fVar1 = fVar1 + 360.0;
      }
      if (180.0 < fVar1) {
        fVar1 = fVar1 - 360.0;
      }
      if (0x3f < (byte)((-180.0 < local_c[0] | (byte)((ushort)((ushort)NAN(local_c[0]) << 10) >> 8)
                        | (byte)((ushort)((ushort)(local_c[0] == -180.0) << 0xe) >> 8)) - 1)) {
        local_c[0] = local_c[0] + 360.0;
      }
      if (180.0 < local_c[0]) {
        local_c[0] = local_c[0] - 360.0;
      }
      *(float *)(*param_1 + 0x5c) = gpGlobals[1] * 40.0 * fVar1;
      *(float *)(*param_1 + 0x60) = gpGlobals[1] * 40.0 * local_c[0];
      iVar2 = *param_1;
      if ((*(byte *)(iVar2 + 0x1a0) & 4) == 0) {
        local_18 = *(float *)(iVar2 + 0x24) * 0.8;
        local_14 = *(float *)(iVar2 + 0x28) * 0.8;
        *(float *)(iVar2 + 0x20) = *(float *)(iVar2 + 0x20) * 0.8;
        *(float *)(iVar2 + 0x24) = local_18;
        *(float *)(iVar2 + 0x28) = local_14;
        iVar2 = *param_1;
        fVar1 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                     *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                     *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
        if (0x3f < (byte)((10.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == 10.0) << 0xe) >> 8)) - 1)) {
          *(undefined4 *)(iVar2 + 0x20) = g_vecZero;
          *(undefined4 *)(iVar2 + 0x24) = DAT_001a7e04;
          *(undefined4 *)(iVar2 + 0x28) = DAT_001a7e08;
        }
      }
      *(float *)(*param_1 + 0x104) = *gpGlobals;
      Move__14CTriggerCamera(param_1);
    }
  }
  return;
}


