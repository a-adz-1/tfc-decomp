// FInViewCone__12CBaseMonsterP11CBaseEntity  @ 000c4e40
bool FInViewCone__12CBaseMonsterP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_28;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  local_28 = *(float *)(*param_2 + 8) - *(float *)(*param_1 + 8);
  fVar1 = *(float *)(*param_2 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar2 = SQRT(fVar1 * fVar1 + local_28 * local_28);
  fVar3 = 0.0;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_28 = 0.0;
  }
  else {
    local_28 = (1.0 / fVar2) * local_28;
    fVar3 = (1.0 / fVar2) * fVar1;
  }
  return (float)param_1[0x134] <
         fVar3 * *(float *)(gpGlobals + 0x2c) + local_28 * *(float *)(gpGlobals + 0x28);
}


// FInViewCone__12CBaseMonsterP6Vector  @ 000c4f40
bool FInViewCone__12CBaseMonsterP6Vector(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_28;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  local_28 = *param_2 - *(float *)(*param_1 + 8);
  fVar1 = param_2[1] - *(float *)(*param_1 + 0xc);
  fVar2 = SQRT(fVar1 * fVar1 + local_28 * local_28);
  fVar3 = 0.0;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_28 = 0.0;
  }
  else {
    local_28 = (1.0 / fVar2) * local_28;
    fVar3 = (1.0 / fVar2) * fVar1;
  }
  return (float)param_1[0x134] <
         fVar3 * *(float *)(gpGlobals + 0x2c) + local_28 * *(float *)(gpGlobals + 0x28);
}


// FInViewCone__12CTFSentrygunP11CBaseEntity  @ 000eadf0
bool FInViewCone__12CTFSentrygunP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_28;
  
  UTIL_MakeVectors__FRC6Vector(param_1 + 0x188);
  local_28 = *(float *)(*param_2 + 8) - *(float *)(*param_1 + 8);
  fVar1 = *(float *)(*param_2 + 0xc) - *(float *)(*param_1 + 0xc);
  fVar2 = SQRT(fVar1 * fVar1 + local_28 * local_28);
  fVar3 = 0.0;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    local_28 = 0.0;
  }
  else {
    local_28 = (1.0 / fVar2) * local_28;
    fVar3 = (1.0 / fVar2) * fVar1;
  }
  return (float)param_1[0x134] <
         fVar3 * *(float *)(gpGlobals + 0x2c) + local_28 * *(float *)(gpGlobals + 0x28);
}


