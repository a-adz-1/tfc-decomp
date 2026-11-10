// AnimateUntilDead__7CSprite  @ 000a45ec
void AnimateUntilDead__7CSprite(int *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *gpGlobals;
  fVar2 = *(float *)(*param_1 + 0x1e4);
  if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    Animate__7CSpritef(param_1,(fVar1 - (float)param_1[0x116]) * *(float *)(*param_1 + 0x138));
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    param_1[0x116] = (int)*gpGlobals;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  else {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


