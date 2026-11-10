// SearchThink__11CBaseTurret  @ 0011b900
void SearchThink__11CBaseTurret(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *param_1;
  if (*(int *)(iVar4 + 0x128) != 2) {
    if (1 < *(int *)(iVar4 + 0x128) - 1U) {
      *(undefined4 *)(iVar4 + 0x130) = 0;
      iVar4 = *param_1;
    }
    *(undefined4 *)(iVar4 + 0x128) = 2;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1c2]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x1c2] == 0.0) << 0xe) >> 8)) == 0x40) &&
     (fVar2 = (float)param_1[0x1a7],
     (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
    param_1[0x1c2] = (int)(fVar2 + *gpGlobals);
  }
  (**(code **)(param_1[0x115] + 0x224))(param_1);
  piVar1 = param_1 + 0x13f;
  iVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar4 != 0) {
    iVar4 = __rf__7EHANDLE(piVar1);
    iVar4 = (**(code **)(*(int *)(iVar4 + 0x454) + 0x8c))(iVar4);
    if (iVar4 == 0) {
      __as__7EHANDLEP11CBaseEntity(piVar1,0);
    }
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar4 == 0) {
    (**(code **)(param_1[0x115] + 0x10c))(param_1,0x4b0);
    uVar5 = (**(code **)(param_1[0x115] + 0x134))(param_1);
    __as__7EHANDLEP11CBaseEntity(piVar1,uVar5);
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar4 == 0) {
    fVar2 = *gpGlobals;
    fVar3 = (float)param_1[0x1b7];
    if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
      fVar3 = (float)param_1[0x1c2];
      if (((byte)(0.0 < fVar3 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar3 == 0.0) << 0xe) >> 8)) != 0x40) && (fVar3 < fVar2))
      {
        (**(code **)(param_1[0x115] + 0x21c))(param_1);
      }
    }
    else {
      param_1[0x1b7] = 0;
      param_1[0x1c2] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)Retire__11CBaseTurret;
    }
    fVar2 = (float)param_1[0x1af] * 0.1 + (float)param_1[0x1bf];
    param_1[0x1bf] = (int)fVar2;
    if ((byte)(fVar2 < 360.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 360.0) << 0xe) >> 8)) != 1) {
      param_1[0x1bf] = (int)(fVar2 - 360.0);
    }
    MoveTurret__11CBaseTurret(param_1);
  }
  else {
    param_1[0x1b7] = 0;
    param_1[0x1c2] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)ActiveThink__11CBaseTurret;
  }
  return;
}


