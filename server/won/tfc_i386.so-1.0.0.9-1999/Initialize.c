// Initialize__11CBaseTurret  @ 00113fe0
void Initialize__11CBaseTurret(int *param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  
  param_1[0x18e] = 0;
  param_1[399] = 0;
  param_1[0x185] = 0;
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  if (param_1[0x18b] == 0) {
    fVar1 = gpGlobals[5];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x18b] = 0x1e;
    }
    else {
      param_1[0x18b] = 0x3c;
    }
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x195]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x195] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x195] = 0x41700000;
  }
  param_1[0x197] = *(int *)(*param_1 + 0x54);
  if (param_1[0x18d] == 1) {
    *(undefined4 *)(*param_1 + 0x84) = 0x43340000;
    *(undefined4 *)(*param_1 + 0x50) = 0x43340000;
    *(float *)(*param_1 + 0x15c) = -*(float *)(*param_1 + 0x15c);
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x10;
    *(float *)(*param_1 + 0x54) = *(float *)(*param_1 + 0x54) + 180.0;
    iVar2 = *param_1;
    fVar1 = *(float *)(iVar2 + 0x54);
    if ((byte)(360.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) == 1) {
      *(float *)(iVar2 + 0x54) = *(float *)(iVar2 + 0x54) - 360.0;
    }
  }
  param_1[0x19b] = 0;
  pfVar3 = gpGlobals;
  if (param_1[400] == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  }
  else {
    param_1[0x194] = (int)(*gpGlobals + (float)param_1[0x195]);
    param_1[3] = -0x10000;
    param_1[4] = (int)AutoSearchThink__11CBaseTurret;
    *(float *)(*param_1 + 0xe4) = *pfVar3 + 0.1;
  }
  return;
}


// Initialize__9CSoundEnt  @ 000ee2e0
void Initialize__9CSoundEnt(int param_1)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  *(undefined4 *)(param_1 + 0x3cc) = 0;
  *(undefined4 *)(param_1 + 0x3d0) = 0xffffffff;
  iVar2 = 0;
  do {
    iVar1 = iVar2;
    Clear__6CSound(param_1 + 0x3dc + iVar1 * 0x20);
    iVar2 = iVar1 + 1;
    *(int *)(iVar1 * 0x20 + param_1 + 0x3f4) = iVar2;
  } while (iVar2 < 0x40);
  *(undefined4 *)(iVar1 * 0x20 + 0x3f4 + param_1) = 0xffffffff;
  iVar2 = 0;
  while( true ) {
    if (*(int *)(gpGlobals + 0x90) <= iVar2) {
      lVar3 = (longdouble)(*DAT_001755a4)("displaysoundlist");
      if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)1) || NAN(lVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)((longdouble)1 == lVar3) << 0xe) >> 8)) == 0x40) {
        *(undefined4 *)(param_1 + 0x3d8) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x3d8) = 0;
      }
      return;
    }
    iVar1 = IAllocSound__9CSoundEnt(pSoundEnt);
    if (iVar1 == -1) break;
    *(undefined4 *)(iVar1 * 0x20 + pSoundEnt + 0x3f0) = 0xbf800000;
    iVar2 = iVar2 + 1;
  }
  (*DAT_001755b4)(1,"Could not AllocSound() for Client Reserve! (DLL)\n");
  return;
}


