// Initialize__11CBaseTurret  @ 0011a9d4
void Initialize__11CBaseTurret(int *param_1)

{
  float fVar1;
  
  param_1[0x1b1] = 0;
  param_1[0x1b2] = 0;
  param_1[0x1a8] = 0;
  SetBoneController__14CBaseAnimatingif(param_1,0,0);
  SetBoneController__14CBaseAnimatingif(param_1,1,0);
  if (param_1[0x1ae] == 0) {
    fVar1 = gpGlobals[5];
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x1ae] = 0x1e;
    }
    else {
      param_1[0x1ae] = 0x3c;
    }
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1b8]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x1b8] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x1b8] = 0x41700000;
  }
  param_1[0x1ba] = *(int *)(*param_1 + 0x54);
  if (param_1[0x1b0] == 1) {
    *(undefined4 *)(*param_1 + 0xa4) = 0x43340000;
    *(undefined4 *)(*param_1 + 0x50) = 0x43340000;
    *(float *)(*param_1 + 0x17c) = -*(float *)(*param_1 + 0x17c);
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x10;
    *(float *)(*param_1 + 0x54) = *(float *)(*param_1 + 0x54) + 180.0;
    fVar1 = *(float *)(*param_1 + 0x54);
    if (0x3f < (byte)((fVar1 < 360.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 360.0) << 0xe) >> 8)) - 1)) {
      *(float *)(*param_1 + 0x54) = fVar1 - 360.0;
    }
  }
  param_1[0x1be] = 0;
  if (param_1[0x1b3] == 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_DoNothing__11CBaseEntity;
  }
  else {
    param_1[0x1b7] = (int)(*gpGlobals + (float)param_1[0x1b8]);
    param_1[3] = -0x10000;
    param_1[4] = (int)AutoSearchThink__11CBaseTurret;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// Initialize__9CSoundEnt  @ 000f2c58
void Initialize__9CSoundEnt(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  int local_8;
  
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  *(undefined4 *)(param_1 + 0x45c) = 0xffffffff;
  iVar4 = local_8;
  do {
    local_8 = iVar4;
    puVar2 = (undefined4 *)(param_1 + 0x468 + local_8 * 0x20);
    *puVar2 = g_vecZero;
    puVar2[1] = DAT_0019f664;
    puVar2[2] = DAT_0019f668;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0xffffffff;
    puVar2[7] = 0;
    iVar4 = local_8 + 1;
    *(int *)(local_8 * 0x20 + param_1 + 0x480) = iVar4;
  } while (iVar4 < 0x40);
  iVar4 = local_8 * 0x20;
  local_8 = 0;
  *(undefined4 *)(iVar4 + param_1 + 0x480) = 0xffffffff;
  while( true ) {
    iVar4 = pSoundEnt;
    if (*(int *)(gpGlobals + 0x90) <= local_8) {
      lVar5 = (longdouble)(*DAT_0019f784)("displaysoundlist");
      if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)1) || NAN(lVar5)) << 10) >> 8) |
                (byte)((ushort)((ushort)((longdouble)1 == lVar5) << 0xe) >> 8)) == 0x40) {
        *(undefined4 *)(param_1 + 0x464) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x464) = 0;
      }
      return;
    }
    iVar3 = *(int *)(pSoundEnt + 0x458);
    if (iVar3 == -1) break;
    iVar1 = pSoundEnt + 0x480;
    puVar2 = (undefined4 *)(pSoundEnt + 0x45c);
    *(undefined4 *)(pSoundEnt + 0x458) = *(undefined4 *)(iVar3 * 0x20 + iVar1);
    *(undefined4 *)(iVar3 * 0x20 + iVar1) = *puVar2;
    *(int *)(iVar4 + 0x45c) = iVar3;
    *(undefined4 *)(iVar3 * 0x20 + pSoundEnt + 0x47c) = 0xbf800000;
    local_8 = local_8 + 1;
  }
  (*DAT_0019f794)(1,"Free Sound List is full!\n");
  (*DAT_0019f794)(1,"Could not AllocSound() for Client Reserve! (DLL)\n");
  return;
}


