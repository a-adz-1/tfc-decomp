// Initialize__11CBaseTurret  @ 00116b98
void Initialize__11CBaseTurret(int *param_1)

{
  float fVar1;
  int iVar2;
  
  param_1[0x1ad] = 0;
  param_1[0x1ae] = 0;
  param_1[0x1a4] = 0;
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  if (param_1[0x1aa] == 0) {
    fVar1 = gpGlobals[5];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x1aa] = 0x1e;
    }
    else {
      param_1[0x1aa] = 0x3c;
    }
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1b4]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x1b4] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x1b4] = 0x41700000;
  }
  param_1[0x1b6] = *(int *)(*param_1 + 0x54);
  if (param_1[0x1ac] == 1) {
    *(undefined4 *)(*param_1 + 0xa4) = 0x43340000;
    *(undefined4 *)(*param_1 + 0x50) = 0x43340000;
    *(float *)(*param_1 + 0x17c) = -*(float *)(*param_1 + 0x17c);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x10;
    *(float *)(*param_1 + 0x54) = *(float *)(*param_1 + 0x54) + 180.0;
    iVar2 = *param_1;
    if (360.0 < *(float *)(iVar2 + 0x54)) {
      *(float *)(iVar2 + 0x54) = *(float *)(iVar2 + 0x54) - 360.0;
    }
  }
  param_1[0x1ba] = 0;
  if (param_1[0x1af] == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  }
  else {
    param_1[0x1b3] = (int)(*gpGlobals + (float)param_1[0x1b4]);
    param_1[3] = -0x10000;
    param_1[4] = (int)AutoSearchThink__11CBaseTurret;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// Initialize__9CSoundEnt  @ 000f0cc0
void Initialize__9CSoundEnt(int param_1)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  *(undefined4 *)(param_1 + 0x448) = 0;
  *(undefined4 *)(param_1 + 0x44c) = 0xffffffff;
  iVar2 = 0;
  do {
    iVar1 = iVar2;
    Clear__6CSound(param_1 + 0x458 + iVar1 * 0x20);
    iVar2 = iVar1 + 1;
    *(int *)(iVar1 * 0x20 + param_1 + 0x470) = iVar2;
  } while (iVar2 < 0x40);
  *(undefined4 *)(iVar1 * 0x20 + 0x470 + param_1) = 0xffffffff;
  iVar2 = 0;
  while( true ) {
    if (*(int *)(gpGlobals + 0x90) <= iVar2) {
      lVar3 = (longdouble)(*DAT_001c1104)("displaysoundlist");
      if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)1.0) || NAN(lVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)((longdouble)1.0 == lVar3) << 0xe) >> 8)) == 0x40) {
        *(undefined4 *)(param_1 + 0x454) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x454) = 0;
      }
      return;
    }
    iVar1 = IAllocSound__9CSoundEnt(pSoundEnt);
    if (iVar1 == -1) break;
    *(undefined4 *)(iVar1 * 0x20 + pSoundEnt + 0x46c) = 0xbf800000;
    iVar2 = iVar2 + 1;
  }
  (*DAT_001c1114)(1,"Could not AllocSound() for Client Reserve! (DLL)\n");
  return;
}


