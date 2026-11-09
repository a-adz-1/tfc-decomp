// FollowTarget__14CTriggerCamera  @ 00112a90
void FollowTarget__14CTriggerCamera(int *param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0xf5);
  if (iVar4 != 0) {
    iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0xf7);
    if (iVar4 != 0) {
      fVar1 = (float)param_1[0xfc];
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        piVar7 = (int *)__rf__7EHANDLE(param_1 + 0xf7);
        iVar4 = *piVar7;
        local_1c = *(float *)(iVar4 + 8) - *(float *)(*param_1 + 8);
        local_18 = *(float *)(iVar4 + 0xc) - *(float *)(*param_1 + 0xc);
        local_14 = *(float *)(iVar4 + 0x10) - *(float *)(*param_1 + 0x10);
        UTIL_VecToAngles__FRC6Vector(&local_10,&local_1c);
        local_10 = -local_10;
        iVar4 = *param_1;
        fVar1 = *(float *)(iVar4 + 0x54);
        if ((byte)(360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) == 1) {
          *(float *)(iVar4 + 0x54) = *(float *)(iVar4 + 0x54) - 360.0;
        }
        iVar4 = *param_1;
        if (*(float *)(iVar4 + 0x54) < 0.0) {
          *(float *)(iVar4 + 0x54) = *(float *)(iVar4 + 0x54) + 360.0;
        }
        pfVar3 = gpGlobals;
        fVar1 = local_10 - *(float *)(*param_1 + 0x50);
        local_c = local_c - *(float *)(*param_1 + 0x54);
        if (fVar1 < -180.0) {
          fVar1 = fVar1 + 360.0;
        }
        if ((byte)(180.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 180.0) << 0xe) >> 8)) == 1) {
          fVar1 = fVar1 - 360.0;
        }
        if (local_c < -180.0) {
          local_c = local_c + 360.0;
        }
        if ((byte)(180.0 < local_c | (byte)((ushort)((ushort)NAN(local_c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_c == 180.0) << 0xe) >> 8)) == 1) {
          local_c = local_c - 360.0;
        }
        *(float *)(*param_1 + 0x5c) = fVar1 * 40.0 * gpGlobals[1];
        *(float *)(*param_1 + 0x60) = local_c * 40.0 * pfVar3[1];
        iVar4 = *param_1;
        if ((*(byte *)(iVar4 + 0x180) & 4) == 0) {
          local_18 = *(float *)(iVar4 + 0x24) * 0.8;
          local_14 = *(float *)(iVar4 + 0x28) * 0.8;
          *(float *)(iVar4 + 0x20) = *(float *)(iVar4 + 0x20) * 0.8;
          *(float *)(iVar4 + 0x24) = local_18;
          *(float *)(iVar4 + 0x28) = local_14;
          iVar4 = *param_1;
          local_1c = SQRT(*(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28) +
                          *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                          *(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20));
          if (local_1c < 10.0) {
            *(undefined4 *)(iVar4 + 0x20) = g_vecZero;
            *(undefined4 *)(iVar4 + 0x24) = DAT_00175484;
            *(undefined4 *)(iVar4 + 0x28) = DAT_00175488;
          }
        }
        *(float *)(*param_1 + 0xe4) = *gpGlobals;
        Move__14CTriggerCamera(param_1);
        return;
      }
    }
    piVar7 = param_1 + 0xf5;
    iVar4 = __rf__7EHANDLE(piVar7);
    iVar4 = (**(code **)(*(int *)(iVar4 + 0x3c8) + 0x88))(iVar4);
    if (iVar4 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(piVar7);
      piVar5 = (int *)__rf__7EHANDLE(piVar7,*(undefined4 *)(*piVar5 + 0x1e8));
      (*DAT_00175630)(*(undefined4 *)(*piVar5 + 0x1e8));
      uVar6 = __opP11CBaseEntity__7EHANDLE(piVar7,1);
      EnableControl__11CBasePlayeri(uVar6);
    }
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,param_1,3,0);
    iVar4 = *param_1;
    *(undefined4 *)(iVar4 + 0x5c) = 0;
    *(undefined4 *)(iVar4 + 0x60) = 0;
    *(undefined4 *)(iVar4 + 100) = 0;
    param_1[0x103] = 0;
  }
  return;
}


