// SearchThink__11CBaseTurret  @ 00115260
void SearchThink__11CBaseTurret(int *param_1)

{
  int *piVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  undefined4 uVar5;
  
  SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  pfVar3 = gpGlobals;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  if (((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x19f]) << 10) >> 8) |
             (byte)((ushort)((ushort)((float)param_1[0x19f] == 0.0) << 0xe) >> 8)) == 0x40) &&
     (fVar2 = (float)param_1[0x184],
     (byte)(fVar2 < 0.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40)) {
    param_1[0x19f] = (int)(*pfVar3 + (float)param_1[0x184]);
  }
  (**(code **)(param_1[0xf2] + 0x21c))(param_1);
  piVar1 = param_1 + 0x11c;
  iVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar4 != 0) {
    iVar4 = __rf__7EHANDLE(piVar1);
    iVar4 = (**(code **)(*(int *)(iVar4 + 0x3c8) + 0x88))(iVar4);
    if (iVar4 == 0) {
      __as__7EHANDLEP11CBaseEntity(piVar1,0);
    }
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
  if (iVar4 == 0) {
    (**(code **)(param_1[0xf2] + 0x104))(param_1,0x4b0);
    uVar5 = (**(code **)(param_1[0xf2] + 300))(param_1);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x11c,uVar5);
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
  if (iVar4 == 0) {
    if (*gpGlobals <= (float)param_1[0x194]) {
      fVar2 = (float)param_1[0x19f];
      if (((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 0x40) &&
         ((float)param_1[0x19f] < *gpGlobals)) {
        (**(code **)(param_1[0xf2] + 0x214))(param_1);
      }
    }
    else {
      param_1[0x194] = 0;
      param_1[0x19f] = 0;
      param_1[3] = -0x10000;
      param_1[4] = (int)Retire__11CBaseTurret;
    }
    fVar2 = (float)param_1[0x18c] * 0.1 + (float)param_1[0x19c];
    param_1[0x19c] = (int)fVar2;
    if ((byte)((360.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == 360.0) << 0xe) >> 8)) - 1) < 0x40) {
      param_1[0x19c] = (int)(fVar2 - 360.0);
    }
    MoveTurret__11CBaseTurret(param_1);
  }
  else {
    param_1[0x194] = 0;
    param_1[0x19f] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)ActiveThink__11CBaseTurret;
  }
  return;
}


