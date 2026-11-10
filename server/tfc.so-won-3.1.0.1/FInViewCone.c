// FInViewCone__12CBaseMonsterP11CBaseEntity  @ 000b337c
bool FInViewCone__12CBaseMonsterP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float local_24;
  float local_20;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  local_24 = *(float *)(*param_2 + 8) - *(float *)(*param_1 + 8);
  local_20 = *(float *)(*param_2 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar1 = SQRT(local_20 * local_20 + local_24 * local_24);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = 0.0;
    local_20 = 0.0;
  }
  else {
    local_24 = (1.0 / fVar1) * local_24;
    local_20 = (1.0 / fVar1) * local_20;
  }
  return (float)param_1[0x137] <
         local_20 * *(float *)(gpGlobals + 0x2c) + local_24 * *(float *)(gpGlobals + 0x28);
}


// FInViewCone__12CBaseMonsterP6Vector  @ 000b34bc
bool FInViewCone__12CBaseMonsterP6Vector(int *param_1,float *param_2)

{
  float fVar1;
  float local_24;
  float local_20;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  local_24 = *param_2 - *(float *)(*param_1 + 8);
  local_20 = param_2[1] - *(float *)(*param_1 + 0xc);
  fVar1 = SQRT(local_20 * local_20 + local_24 * local_24);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = 0.0;
    local_20 = 0.0;
  }
  else {
    local_24 = (1.0 / fVar1) * local_24;
    local_20 = (1.0 / fVar1) * local_20;
  }
  return (float)param_1[0x137] <
         local_20 * *(float *)(gpGlobals + 0x2c) + local_24 * *(float *)(gpGlobals + 0x28);
}


// FInViewCone__12CTFSentrygunP11CBaseEntity  @ 000e07e4
bool FInViewCone__12CTFSentrygunP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float local_24;
  float local_20;
  
  UTIL_MakeVectors__FRC6Vector(param_1 + 0x18c);
  local_24 = *(float *)(*param_2 + 8) - *(float *)(*param_1 + 8);
  local_20 = *(float *)(*param_2 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar1 = SQRT(local_20 * local_20 + local_24 * local_24);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_24 = 0.0;
    local_20 = 0.0;
  }
  else {
    local_24 = (1.0 / fVar1) * local_24;
    local_20 = (1.0 / fVar1) * local_20;
  }
  return (float)param_1[0x137] <
         local_20 * *(float *)(gpGlobals + 0x2c) + local_24 * *(float *)(gpGlobals + 0x28);
}


