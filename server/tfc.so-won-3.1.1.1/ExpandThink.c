// ExpandThink__7CSprite  @ 000a44dc
void ExpandThink__7CSprite(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x116];
  iVar3 = *param_1;
  *(float *)(iVar3 + 0x144) =
       *(float *)(iVar3 + 0x1f8) * (fVar1 - fVar2) + *(float *)(iVar3 + 0x144);
  iVar3 = *param_1;
  *(float *)(iVar3 + 0x14c) =
       *(float *)(iVar3 + 0x14c) - (fVar1 - fVar2) * *(float *)(iVar3 + 0x160);
  iVar3 = *param_1;
  fVar1 = *(float *)(iVar3 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    *(float *)(iVar3 + 0x104) = *gpGlobals + 0.1;
    param_1[0x116] = (int)*gpGlobals;
  }
  else {
    *(undefined4 *)(iVar3 + 0x14c) = 0;
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


