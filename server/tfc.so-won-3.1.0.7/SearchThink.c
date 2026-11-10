// SearchThink__11CBaseTurret  @ 00117f20
void SearchThink__11CBaseTurret(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  
  SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1be]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x1be] == 0.0) << 0xe) >> 8)) == 0x40) &&
     (fVar2 = (float)param_1[0x1a3],
     (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
    param_1[0x1be] = (int)(*gpGlobals + (float)param_1[0x1a3]);
  }
  (**(code **)(param_1[0x111] + 0x224))(param_1);
  piVar1 = param_1 + 0x13b;
  iVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar4 != 0) {
    iVar4 = __rf__7EHANDLE(piVar1);
    iVar4 = (**(code **)(*(int *)(iVar4 + 0x444) + 0x8c))(iVar4);
    if (iVar4 == 0) {
      __as__7EHANDLEP11CBaseEntity(piVar1,0);
    }
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
  if (iVar4 == 0) {
    (**(code **)(param_1[0x111] + 0x10c))(param_1,0x4b0);
    uVar5 = (**(code **)(param_1[0x111] + 0x134))(param_1);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x13b,uVar5);
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13b);
  if (iVar4 == 0) {
    fVar2 = *gpGlobals;
    fVar3 = (float)param_1[0x1b3];
    if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
      fVar2 = (float)param_1[0x1be];
      if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) {
        fVar2 = *gpGlobals;
        fVar3 = (float)param_1[0x1be];
        if (0x3f < (byte)((fVar2 < fVar3 |
                           (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) {
          (**(code **)(param_1[0x111] + 0x21c))(param_1);
        }
      }
    }
    else {
      param_1[0x1b3] = 0;
      param_1[0x1be] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)Retire__11CBaseTurret;
    }
    fVar2 = (float)param_1[0x1ab] * 0.1 + (float)param_1[0x1bb];
    param_1[0x1bb] = (int)fVar2;
    if (360.0 <= fVar2) {
      param_1[0x1bb] = (int)(fVar2 - 360.0);
    }
    MoveTurret__11CBaseTurret(param_1);
  }
  else {
    param_1[0x1b3] = 0;
    param_1[0x1be] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)ActiveThink__11CBaseTurret;
  }
  return;
}


