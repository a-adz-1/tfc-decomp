// TumbleThink__8CGrenade  @ 000b99d0
void TumbleThink__8CGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar4 = (**(code **)(param_1[0xf2] + 0x98))(param_1);
  if (iVar4 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
    pfVar3 = gpGlobals;
    local_8 = *gpGlobals + 0.1;
    *(float *)(*param_1 + 0xe4) = local_8;
    iVar4 = *param_1;
    fVar2 = *(float *)(iVar4 + 0x1c4) - 1.0;
    fVar1 = *pfVar3;
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
      fVar1 = *(float *)(iVar4 + 0x1c4) - *pfVar3;
      local_14 = *(float *)(iVar4 + 8) + fVar1 * *(float *)(iVar4 + 0x20);
      local_10 = *(float *)(iVar4 + 0xc) + fVar1 * *(float *)(iVar4 + 0x24);
      local_c = *(float *)(iVar4 + 0x10) + fVar1 * *(float *)(iVar4 + 0x28);
      InsertSound__9CSoundEntiRC6Vectorif(0x20,&local_14,400,0x3dcccccd);
    }
    fVar1 = *(float *)(*param_1 + 0x1c4);
    fVar2 = *gpGlobals;
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
      param_1[3] = -0x10000;
      param_1[4] = (int)Detonate__8CGrenade;
    }
    iVar4 = *param_1;
    if (*(int *)(iVar4 + 0x1a0) != 0) {
      *(float *)(iVar4 + 0x20) = *(float *)(iVar4 + 0x20) * 0.5;
      *(float *)(iVar4 + 0x24) = *(float *)(iVar4 + 0x24) * 0.5;
      *(float *)(iVar4 + 0x28) = *(float *)(iVar4 + 0x28) * 0.5;
      *(undefined4 *)(*param_1 + 0x118) = 0x3e4ccccd;
    }
  }
  return;
}


