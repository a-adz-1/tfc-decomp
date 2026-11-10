// TumbleThink__8CGrenade  @ 000b15d8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TumbleThink__8CGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = (**(code **)(param_1[0x115] + 0x9c))(param_1);
  if (iVar3 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
    local_8 = (float)_FUN_0014c210 + *gpGlobals;
    *(float *)(*param_1 + 0x104) = local_8;
    iVar3 = *param_1;
    fVar2 = *(float *)(iVar3 + 0x1e4) - 1.0;
    fVar1 = *gpGlobals;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      fVar1 = *(float *)(iVar3 + 0x1e4) - fVar1;
      local_14 = *(float *)(iVar3 + 0x20) * fVar1 + *(float *)(iVar3 + 8);
      local_10 = *(float *)(iVar3 + 0x24) * fVar1 + *(float *)(iVar3 + 0xc);
      local_c = fVar1 * *(float *)(iVar3 + 0x28) + *(float *)(iVar3 + 0x10);
      InsertSound__9CSoundEntiRC6Vectorif(0x20,&local_14,400,0x3dcccccd);
      iVar3 = *param_1;
    }
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(iVar3 + 0x1e4);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      param_1[3] = -0x10000;
      param_1[4] = (int)Detonate__8CGrenade;
      iVar3 = *param_1;
    }
    if (*(int *)(iVar3 + 0x1c0) != 0) {
      *(float *)(iVar3 + 0x20) = *(float *)(iVar3 + 0x20) * 0.5;
      *(float *)(iVar3 + 0x24) = *(float *)(iVar3 + 0x24) * 0.5;
      *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) * 0.5;
      *(undefined4 *)(*param_1 + 0x138) = 0x3e4ccccd;
    }
  }
  return;
}


